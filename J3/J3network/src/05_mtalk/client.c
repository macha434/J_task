/*********************************************/
/*       File name:  client.c                */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* �ߥ��ŻҲ�ĥ��饤����ȥץ���� */

#include "session.h"
#include "mylib.h"
#include <stdlib.h>
int main(void)
{
  int   soc;                       /* �����å� */
  char  hostname[HOSTNAME_LENGTH]; /* �����ФΥۥ���̾ */

  /* �����ФΥۥ���̾������ */
  printf("input server's hostname = ");
  fgets(hostname, HOSTNAME_LENGTH, stdin);
  chop_newline(hostname, HOSTNAME_LENGTH);

  /* ���饤����ȤȤ��ƤΥ��åȥ��å� */
  if ((soc = setup_client(hostname, PORT)) == -1) {
    exit(0);
  }

  /* ���å����⥸�塼��ν���� */
  session_init(soc);

  /* ���å����Υᥤ��롼�� */
  session_loop();
  return 0;
}
