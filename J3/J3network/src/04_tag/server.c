/*********************************************/
/*       File name:  server.c                */
/*    Project name:  socket/tag              */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

/* �����ä�������Υ����Хץ���� */

#include "session.h"
#include "tag.h"

/*�ɲåإå�*/
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  int soc;   /* �����åȤΥǥ�������ץ� */

  /* ��³���դޤ� */
  if ((soc = setup_server(PORT) ) == -1) {
    exit(1);
  }

  /* ���å����⥸�塼��ν���� */
  session_init(soc, 'o', 1, 1, 'x', 10, 10);

  /* ���å����Υ롼�� */
  session_loop();
  return 0;
}
