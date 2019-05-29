#define BASETIME 8

unsigned char sound_pat[BASETIME]; /* �ȷ��ѥ��������� */
unsigned char loud; /* �������� (0-255) */
unsigned char mute; /* ����:0, ����¾:1 */

extern unsigned int sound(unsigned int s_tempo, int s_long, 
			  char *s_tone, int tone_ch);
     /* 1����Ф�����δؿ�                                           */
     /*  s_tempo: ���եƥ��(60������1��)                             */
     /*  s_long : Ĺ������(1:������ - 32:32ʬ����, �����������)      */
     /*  s_tone : �⤵����                                            */
     /*             CDEFGAB�� #/b(Ⱦ���夲/����), +/-(���������־岼) */
     /*           ����� CDEFGAB �ʳ���ʸ����ǽ�������             */
     /*  tone_ch: �����ѥ����ޤΥ���ͥ����                          */
     /* �����: ����Ĺ��(ms)                                          */
     /* ���: �ƤӽФ����� sound_pat ���ȷ��ѥ����������Ƥ�������   */

/* �����˥ץ��������������ϰʲ��δؿ�����Ѥ��뤳�� */
extern unsigned int sound_tone(char *s_tone);
     /* �����Ѥγ����ߴ��֤����ؿ�                              */
     /*  s_tone : �⤵����                                            */
     /*             CDEFGAB�� #/b(Ⱦ���夲/����), +/-(���������־岼) */
     /*             ����� CDEFGAB �ʳ���ʸ����ǽ�������           */
     /* �����: �����ѳ����ߴ��� (us)                               */
extern unsigned long sound_period(unsigned int tempo, char *period);
     /* ����Ĺ����׻�����ؿ�                                      */
     /*   s_tempo: ���եƥ�� (4ʬ�����/ʬ)                        */
     /*   s_long : Ĺ���Υǡ��������ä�ʸ������                     */
     /*     [0][1]: ��������(1,2,4,8,16,32) [2]: ������3Ϣ��(.,t) */
