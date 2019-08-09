/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* �����ä�������Υ��饤����ȥץ������ */

#include "session.h"
#include "tag.h"
/*�ɲåإå�*/
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int soc;    /* �����åȤΥǥ�������ץ� */
  char hostname[HOSTNAME_LENGTH]; /* ������(���)�Υۥ���̾ */

  /* �����ФΥۥ���̾������ */
  printf("input  server's  hostname: ");
  fgets(hostname, HOSTNAME_LENGTH, stdin);
  chop_newline(hostname, HOSTNAME_LENGTH);

  /* ��³�ޤ� */
  if ((soc = setup_client(hostname,PORT) ) == -1) {
    exit(1);
  }

  /* ���å����⥸�塼��ν���� */
  session_init(soc, 'x', 10,10, 'o',1, 1);

  /* ���å����Υ롼�� */
  session_loop();
  return 0;
}