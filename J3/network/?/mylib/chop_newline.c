/*********************************************/
/*       File name:  chop_newline.c          */
/*    Project name:  socket/mylib            */
/*      Month/Year:  Jan/2003                */
/*          Author:  Shuichi YUKITA          */
/*********************************************/

#include "mylib.h"

char * chop_newline(char *str, int len)
	/* �����  Ϳ����줿ʸ�������Ƭ���ɥ쥹           */
	/* str     ����ʸ���ǽ���äƤ��뤫���Τ�ʤ�ʸ���� */
	/* len     ����������                               */
{
	int n = strlen(str); /* Ϳ����줿ʸ�����Ĺ�� */

	/* ����������ʸ���ʤ��� */
	if(n<len &&str[n-1]=='\n'){
		str[n-1]='\0';
	}

	/* ��Ƭ���Ϥ��֤� */
	return str;
}
