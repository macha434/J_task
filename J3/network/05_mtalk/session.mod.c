/*********************************************/
/*       File name:  session.c               */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <curses.h>

#define BUF_LEN 80

/* �����ѥ�����ɥ��Υ����� */
#define SEND_WIN_WIDTH 60
#define SEND_WIN_HEIGHT 1

/* �����ѥ�����ɥ��Υ����� */
#define RECV_WIN_WIDTH 60
#define RECV_WIN_HEIGHT 13

/* �����Ѥȼ����ѤΥ�����ɥ���ʬ���� */
static WINDOW  *win_send, *win_recv;
static WINDOW  *frame_send, *frame_recv;

/* �̿��Ѥ��ѿ� */
static char    send_buf[BUF_LEN];  /* �����Хåե� */
static char    recv_buf[BUF_LEN];  /* �����Хåե� */
static int     session_soc;	  /* �����å�     */
static fd_set  mask;               /* select�ѽ�����ޥ��� */
static int     width;              /* �ޥ������� */

/* ��λ�����δؿ� */
static void  die();


/********************/
/* ���������ؿ��� */
/********************/

/*  ���å����ν����  */
void  session_init(int  soc)
	/* soc  �����å� */
{
  /* select �ѥޥ���������    */
  session_soc = soc;
  width = soc+1;
  FD_ZERO(&mask);
  FD_SET(0, &mask);
  FD_SET(soc, &mask);

  /* curses �ν�����ʤ�  */
  initscr();
  signal(SIGINT, die);

  /* �����ѥ�����ɥ����Ȥ�Ĥ��롣 */
  frame_send = newwin( SEND_WIN_HEIGHT + 2, SEND_WIN_WIDTH + 2, 18, 0);
  win_send = newwin( SEND_WIN_HEIGHT, SEND_WIN_WIDTH, 19, 1);
  box(frame_send, '|', '-');
  scrollok(win_send, TRUE);
  wmove(win_send, 0,0);

  /* �����ѥ�����ɥ����Ȥ�Ĥ��롣 */
  frame_recv = newwin(RECV_WIN_HEIGHT + 2, RECV_WIN_WIDTH + 2, 0, 0);
  win_recv = newwin(RECV_WIN_HEIGHT, RECV_WIN_WIDTH, 1, 1);
  box(frame_recv, '|', '-');
  scrollok(win_recv, TRUE);
  wmove(win_recv, 0,0);

  /* ü��°�����ѹ� */
  cbreak();
  noecho();

  /* ������ɥ���ɽ�� */
  wrefresh(frame_recv);
  wrefresh(win_recv);
  wrefresh(frame_send);
  wrefresh(win_send);
}

/*  ���å����Υᥤ��롼��  */
void  session_loop(void)
{
  int c;         /* �����ܡ��ɤ��������ʸ�� */
  int flag = 1;  /* �롼�׷�³�ե�å�       */
  fd_set readOk; /* select �Υޥ���          */
  int len = 0;	 /* send_buf ��θ��߰���    */
  int i;         /* �롼�ץ�����           */
  int y,x;       /* ��ɸ                     */
  int n;         /* �����Х��ȿ�             */


  while(1) {
    /*  select ��������� readOk ���������롣 */
    readOk = mask;
    select(width, (fd_set *)&readOk, NULL, NULL, NULL);

    /*  �����ܡ��ɤ�������Ϥ��꤫�� */
    if ( FD_ISSET(0, &readOk ) ) {
      c = getchar();

      /* back space �ν��� */
      if (c == '\b' ||  c == 0x10 || c==0x7F ) {
	if (len == 0) continue;
	len--;
	getyx(win_send, y,x);
	wmove(win_send, y, x-1);
	waddch(win_send, ' ');
	wmove(win_send, y, x-1);
      }
      /* ���Ԥ����� */
      else if (c == '\n' || c=='\r'){
	send_buf[len] = '\n';
	len ++;
	write(session_soc, send_buf, len);

	/* Clearing the send window */
	wclear(win_send);
	len = 0;
      }
      /* �ʳ��ν��� */
      else{
	send_buf[len] = c;
	len ++;
	waddch(win_send, c);
      }
      wrefresh(win_send);
    }

    /*  �����åȤ˥ǡ������꤫�� */
    if ( FD_ISSET(session_soc, &readOk ) ) {
      n = read(session_soc, recv_buf, BUF_LEN);
      for (i = 0;  i < n;  i++) {
	waddch(win_recv, recv_buf[i]);
      }

      /* "quit" ��������齪λ */
      if (strstr(recv_buf, "quit") != NULL) {
	flag = 0;
      }
      wrefresh(win_recv);

      /* Move cursor back to the send buffer */
      wrefresh(win_send);
    }


    if (flag == 0) {
      break;
    }
  }
  /* ü��°�������줷�ƽ���� */
  die();
}


static void  die(void)
{
  endwin();
  close(session_soc);

  exit(0);
}
