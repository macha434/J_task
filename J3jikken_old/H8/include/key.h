#define KEYBUFSIZE 10  /* �����Хåե����礭�� */
#define KEYROWNUM 4    /* ������������(�Ĥ��¤�Ǥ���Ŀ�) */
#define KEYCOLNUM 3    /* ��������ιԿ�(�����¤�Ǥ���Ŀ�) */
#define KEYMINNUM  1   /* �����ֹ�κǾ��� */
#define KEYMAXNUM 12   /* �����ֹ�κ����� */
#define KEYNONE   -1   /* ���ꤷ���������ʤ� */
#define KEYOFF     0   /* ���ꤷ�������Ϥ��ä�Υ����Ƥ������ */
#define KEYON      1   /* ���ꤷ�������Ϥ��äȲ�����Ƥ������ */
#define KEYRELEASE 2   /* ���ꤷ�������Ϻ�Υ���줿���� */
#define KEYPUSH    3   /* ���ꤷ�������Ϻ������줿���� */

/* �����޳����߽����Τ���, �Хåե���Ϣ������ѿ��Ȥ��Ƴ��� */
int keybufdp;
unsigned char keybuf[KEYBUFSIZE][KEYROWNUM];

extern void key_init(void);
extern void key_sense(void);
extern int key_check(int keynum);
