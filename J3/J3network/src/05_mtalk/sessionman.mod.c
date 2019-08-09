/*********************************************/
/*       File name:  sessionman.c            */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* �ߥ��ŻҲ�ĤΥ��å��������ץ���� */

#include <stdio.h>
#include "stdc.h"
#include <sys/types.h>

#define	MAX_ATTENDANTS 5
#define BUF_LEN	     80


static char    buf[BUF_LEN];  /* �������Хåե�           */
static fd_set  mask;	     /* select�ѽ�����ޥ���     */
static int     width;         /* �ƻ�ǥ�������ץ����ϰ� */
static int     attendants;    /* ���üԿͿ�               */

/* ���üԴ����Τ���Υǡ�����¤ */
typedef	struct {
  int   fd;
  char  name[16];
} ATTENDANT;

static ATTENDANT  p[MAX_ATTENDANTS]; /* ���üԾ�������� */

/*  session �Υᥤ��롼�פβ������롼���� */
static void  send_all(int i, int n);
static void  ending(void);


/*  enter �� mserver_maccept() ���Ϥ���륳����Хå��ؿ� */
void enter(int  i, int  fd)
	/* i   �����ֹ�                 */
	/* fd  �������˻��Ѥ��륽���å� */
{
  int  j,cnt=0;
  int  len;   /* �����Х��ȿ� */
  static char  *mesg1 = "Type your name within 15characters\n";
  static char  *mesg2 = "wait.\n";
  p[i].fd = fd;
  memset(p[i].name, 0, 16);
  write(fd, mesg1, strlen(mesg1));
  len = read(fd, p[i].name, 16);
  for(j=0;j<len;j++){
    if(p[i].name[j]=='\n') cnt++;
  }
  if(cnt>1) len=read(fd,p[i].name,16);
  
  sprintf(p[i].name + len - 1, "  -->  ");
  write(fd, mesg2, strlen(mesg2));
}


/*  ���å����ν���� */
void sessionman_init(int  num, int  maxfd)
	/* num    attendants �οͿ�    */
	/* maxfd  ����Υǥ�������ץ� */
{
  int  i;                /* �롼�ץ����� */
  static char  *mesg = "Communication Ready.\n";

  attendants = num;     /* ���üԿͿ������� */

  /* select �Τ���Υޥ��������  */
  width = maxfd + 1;
  FD_ZERO(&mask);
  FD_SET(0, &mask);
  for (i = 0;  i < num;  i++) {
    FD_SET(p[i].fd , &mask);
  }

  /* ���å���󳫻ϤΥ�å����������������� */
  for (i = 0;  i < num;  i++) {
    write(p[i].fd, mesg, strlen(mesg));
  }
}

/*  ���å����Υᥤ��롼��  */
void  sessionman_loop(void)
{
  fd_set  readOk;     /* select�Τ���Υޥ��� */
  int  i;             /* �롼�ץ�����       */

  while(1) {
    /*  select ��������� readOk ���������� */
    readOk = mask;
    select(width, (fd_set *)&readOk, NULL, NULL, NULL);

    /*  �����ܡ��ɤ�������Ϥ��꤫�� */
    if ( FD_ISSET(0, &readOk ) ) {
      ending();
    }

    /* �����åȤ���Ĵ�٤� */
    for (i = 0;  i < attendants;  i++) {
      if (FD_ISSET(p[i].fd, &readOk)) {
	int  n;
	
	n = read(p[i].fd, buf, BUF_LEN);
	send_all(i, n);
      }
    }
  }
}


/************************************/
/*  �ᥤ��롼�פβ������롼����ã  */
/************************************/

/* ��λ���� */
static void  ending(void)
{
  int  i;

  for (i = 0;  i < attendants;  i++) {
    write(p[i].fd, "quit", 4);
  }

  for (i = 0;  i < attendants;  i++) {
    close(p[i].fd);
  }

  exit(0);
}

static void  send_all(int  i, int  n)
     /* i  p[i] ��̾�����դ��� */
     /* n  �����Х��ȿ�        */
{
  int  j;

  for (j = 0;  j < attendants;  j++) {
    write(p[j].fd, p[i].name, strlen(p[i].name));
    write(p[j].fd, buf, n);
  }
}
