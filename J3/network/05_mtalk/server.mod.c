/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/mtalk            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* �ߥ��ŻҲ�ĥ����Хץ���� */

#include <stdio.h>
#include "sessionman.h"
#include "mylib.h"


int main(int  argc,  char  *argv[])
	/* argc     2�Ǥ��ä��ߤ��� */
	/* argv[1]  ���üԿͿ�      */
{
  int  num;   /* ���üԿͿ�           */
  int  soc;   /* �Ԥ����������å�     */
  int  maxfd; /* ����Υǥ�������ץ� */

  /* �����ǻ��üԿͿ����Τ롣 */
  if (argc != 2) {
    fprintf(stderr,"Usage: s  attendants\n");
    exit(1);
  }

  /* �������Ѵ�  ʸ���� --> int  */
  if ((num = atoi(argv[1])) <= 0  ||  num > MAX_ATTENDANTS) {
    fprintf(stderr, "attendants limit= %d\n", MAX_ATTENDANTS);
    exit(1);
  }

  /* �����åȤΥǥ�������ץ��� soc �˼������ */
  if ( (soc = mserver_socket(PORT, num)) == -1) {
    fprintf(stderr, "cannot setup server\n");
    exit(1);
  }

  /* m_accept �˥�����Хå��ؿ��� enter ���Ϥ���
     �֤ä����ΤϺ���Υǥ�������ץ� */
  maxfd = mserver_maccept(soc, num, enter);

  /* ���å����⥸�塼��ν���� */
  sessionman_init(num, maxfd);

  /* ���å��������Υᥤ��롼�� */
  sessionman_loop();
  return 0;
}
