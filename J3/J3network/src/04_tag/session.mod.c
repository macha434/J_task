/*********************************************/
/*       File name:  session.c               */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include <sys/types.h>
#include <curses.h>
#include <signal.h>
/*�ɲåإå�*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*�ɲôؿ�*/
#define rand_range(min,max) (min)+(rand())%((max)-(min)+(1))
#define NUMBER 10

#define BUF_LEN 20
#define MIN_X	1
#define MIN_Y	1
#define MAX_X	60
#define MAX_Y	20

static int map_flag[MAX_Y][MAX_X];

/* ��ư�����γ������ */
#define NORTH 'k'
#define SOUTH 'j'
#define EAST  'l'
#define WEST  'h'
#define QUIT  'q'

/* �ץ饤�١����ѿ� */
static  int    session_soc;     /* socket  */
static  fd_set mask;            /* fd mask */
static  int    width;           /* width of the mask */
static  char   my_char, peer_char; /* character */

typedef	struct{
  int x,y;
  char	look;  /* character */
} PLAYER;

static PLAYER  me, peer;    /* ��ʬ�����ξ��֤��ݻ������ѿ�  */

static char  buf[BUF_LEN];  /* ���������ѥХåե� */

static WINDOW  *win;	   /* ɽ���ѥ�����ɥ� */

/*  session �⥸�塼��˥ץ饤�١��Ȥʴؿ�  */
static void  hide(PLAYER *who);
static void  show(PLAYER *who);
static int   update(PLAYER *who, int c);
static int   interpret(PLAYER *who);
static void  die();

/*  session �⥸�塼��ν����  */
void  session_init(int soc,
                   char mc, int mx, int my,
                   char pc, int px, int py)
	   /* soc  �����åȤΥǥ�������ץ� */
	   /* mc   ��ʬ��ɽ���Ѥ�ʸ��       */
	   /* mx   ��ʬ�ν��x��ɸ          */
	   /* my   ��ʬ�ν��y��ɸ          */
	   /* pc   ����ɽ���Ѥ�ʸ��       */
	   /* px   ���ν��x��ɸ          */
	   /* py   ���ν��y��ɸ          */
{
  /* ����ǡ��������� */
  session_soc = soc;
  width = soc + 1;
  FD_ZERO(&mask);
  FD_SET(0, &mask);
  FD_SET(session_soc, &mask);
  me.look = mc;
  peer.look = pc;

  me.x = mx;  me.y = my;
  peer.x = px;  peer.y = py;

  /* curses �ν���� */
  initscr();
  signal(SIGINT, die);

  /* ������ɥ��� */
  win = newwin(MAX_Y + 2, MAX_X + 2, 0, 0);
  box(win, '|', '-');

  /* ü������ */
  cbreak();
  noecho();
}

/*  ������֤�����  */
void set(clock_t TIMES,int flag)
{
  /* ����������� */
  srand(TIMES);

  if(flag==0){                        /* �����С�¦ */
    me.x=rand_range(MIN_X,MAX_X);
    me.y=rand_range(MIN_Y,MAX_Y);
    peer.x=rand_range(MIN_X,MAX_X);
    peer.y=rand_range(MIN_Y,MAX_Y);
  }else{                              /*���饤�����¦*/
    peer.x=rand_range(MIN_X,MAX_X);
    peer.y=rand_range(MIN_Y,MAX_Y);
    me.x=rand_range(MIN_X,MAX_X);
    me.y=rand_range(MIN_Y,MAX_Y);
  }
}

/*  �㳲ʪ������   */
void setter(void)
{
  int x,y;
  for(int i=0;i<NUMBER;i++){
    x=rand_range(MIN_X,MAX_X);
    y=rand_range(MIN_Y,MAX_Y);
    map_flag[y][x]=1;
    wmove(win,y,x);
    waddch(win,'.');
  }
}
/*  session �ᥤ��롼��  */
void  session_loop()
{
  int c;         /* �����ܡ��ɤ��������ʸ�� */
  int flag;      /* �롼�׷�³�ե�å�       */
  fd_set readOk; /* ¿�����ϤΥޥ���         */

  /* ��ʬ�λѤ�ɽ�� */
  show(&me);
  /*���λѤ�ɽ��*/
  show(&peer);
  /* �롼�׷�³�ե�å��ν���� */
  flag = 1;

  /* �롼�� */
  while(1) {
    /*  select ��������� readOk ���������롣 */
    readOk = mask;
    select(width,(fd_set *)&readOk,NULL,NULL,NULL);

    /*  �����ܡ��ɤ�������Ϥ��꤫�� */
    if (FD_ISSET(0, &readOk) ) {
      c = getchar();            /* �����ܡ��ɤ�������     */
      hide(&me);                /* ��ʬ�λѤ򱣤�         */
      flag = update(&me, c);    /* ���֤򹹿�             */
      show(&me);                /* ��ʬ�λѤ򸽤�         */
      write(session_soc, buf, BUF_LEN);  /* �����ǡ��������� */
      if (flag == 0) {  /* �롼��ȴ���Ф�Ƚ��  */
	break;
      }
    }
    /*  �����åȤ˥ǡ������꤫�� */
    if (FD_ISSET(session_soc, &readOk) ) {
      read(session_soc,buf,BUF_LEN); /* �����åȤ�������  */
      hide(&peer);              /* ���λѤ򱣤�         */
      flag = interpret(&peer);  /* ���ξ��֤ι���       */
      show(&peer);              /* ���λѤ򸽤�         */
      if (flag == 0) {  /* �롼��ȴ���Ф�Ƚ��  */
	break;
      }
    }
    
    /*�⤷��ư�褬��ʬ���ä����*/
    if(me.x==peer.x&&me.y==peer.y) break;
  }

  /* ü��°�������줷�ƽ���� */
  die();
}


static void  show(PLAYER *who)
	/* who  ï��ɽ�����뤫  */
{
  wmove(win, who->y, who->x); /* who�ξ���ư��           */
  waddch(win, who->look);     /* ���ξ���who��look���֤� */
  wmove(win, who->y, who->x); /* ����������᤹            */
  wrefresh(win);              /* ������ɥ��ι���          */
}


static void  hide(PLAYER *who)
	/* who  ï�λѤ�ä���  */
{
  wmove(win, who->y, who->x); /* who�ξ���ư��           */
  waddch(win, ' ');           /* ���ξ��˥��ڡ������  */
}


static int  update(PLAYER *who, int c)
	/* who  ï��             */
	/* c    �ɤ����ư������ */
{
  switch (c) {
  case WEST:
    if ( who->x > MIN_X && map_flag[who->y][(who->x)-1]==0) {
      who->x --;
    }
    break;
  case SOUTH:
    if ( who->y < MAX_Y && map_flag[(who->y)+1][who->x]==0) {
      who->y ++;
    }
    break;
  case NORTH:
    if ( who->y > MIN_Y && map_flag[(who->y)-1][who->x]==0) {
      who->y --;
    }
    break;
  case EAST:
    if ( who->x < MAX_X && map_flag[who->y][(who->x)+1]==0) {
      who->x ++;
    }
    break;
  case QUIT:
    buf[0] = QUIT;
    return 0;
  default:
    break;
  }

  /* �������줿���֥ǡ�����������ʸ������Ѵ����� */
  sprintf(buf, "%d %d\n", who->x, who->y);

  return 1;
}

static int  interpret(PLAYER *who)
	/* who ����Υǡ����γ�Ǽ���ؤ� */
{
  /* �⤷��꤬��λ���˾������ */
  if (buf[0] == 'q') {
    return 0;
  }
  
  /* ����ʸ���󤫤���֥ǡ������Ѵ����롣 */
  sscanf(buf, "%d %d", &who->x, &who->y);

  return 1;
}

static void  die()
{
  endwin();  /* ü��°�������� */

  exit(0);
}