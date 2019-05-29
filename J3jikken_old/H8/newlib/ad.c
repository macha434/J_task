#include "h8-3052-iodef.h"

void ad_init();
void ad_start(unsigned char ch, unsigned char int_sw);
void ad_scan(unsigned char ch_grp, unsigned char int_sw);
void ad_stop(void);

void ad_init()
     /* A/D �Ѵ����Ȥ�����ν�����ؿ� */
{
  unsigned char dmy;

  ADCR = 0x7e;  /* �����ȥꥬ�Ѵ����Ϥζػ� */
  dmy = ADCSR;  /* �Ѵ���λ�ե饰���ꥢ�Τ���Υ��ߡ��꡼�� */
  ADCSR = 0x08; /* ñ�쥹�����, �����߶ػ�, A/D�Ѵ����, */
                /* 134���ơ����Ѵ�����, ����ͥ� 0 ����     */
}

void ad_start(unsigned char ch, unsigned char int_sw)
     /* A/D�Ѵ��򥹥����Ȥ�����ؿ�                                */
     /* ch:���ϥ���ͥ��ֹ�(0-7), int_sw:�Ѵ���λ�����ߵ���(0,1) */
     /* �����ߵ��Ĥξ��, ���ӳ����ߥϥ�ɥ餬ɬ��             */
     /* �ޤ�, CPU������ߵ��ľ��֤ˤ��ʤ��ȳ����ߤ�ȯ�����ʤ�  */
     /* �����߽����ˤϿ�us�λ��֤������뤳�Ȥ��θ���뤳��       */
{
  if (int_sw != 0) int_sw = 0x40;
  else int_sw = 0;
  ADCSR = (ADCSR & 0xd8) | (ch & 0x07);   /* �Ѵ����, ����ͥ�ν񤭴��� */
  ADCSR = (ADCSR & 0x1f) | 0x20 | int_sw; /* ����ɥե饰���ꥢ, �Ѵ����� */
}

void ad_scan(unsigned char ch_grp, unsigned char int_sw)
     /* A/D�Ѵ��򥹥����⡼�ɤǥ������Ȥ�����ؿ�                */
     /* ch_grp:���ϥ���ͥ륰�롼�׻���(0,1)                       */
     /*   0:AN0-AN3 ��ưŪ�˥�����󤷤Ʒ�̤�쥸�����˳�Ǽ     */
     /*   1:AN4-AN7 ��ưŪ�˥�����󤷤Ʒ�̤�쥸�����˳�Ǽ     */
     /* int_sw:���롼�ץ�������Ѵ���λ�����ߵ���(0,1)           */
     /* �����ߵ��Ĥξ��, ���ӳ����ߥϥ�ɥ餬ɬ��             */
     /* �ޤ�, CPU������ߵ��ľ��֤ˤ��ʤ��ȳ����ߤ�ȯ�����ʤ�  */
     /* �����߽����ˤϿ�us�λ��֤������뤳�Ȥ��θ���뤳��       */
{
  if (int_sw != 0) int_sw = 0x40; /* �Ѵ���λ���˳��������� */
  else int_sw = 0;                /* �����ߤ���Ѥ��ʤ�     */
  if (ch_grp != 0) ch_grp = 7;    /* AN4-7�μ�ư������� */
  else ch_grp = 3;                /* AN0-3�μ�ư������� */
  ADCSR = ADCSR & 0x5f;           /* ����ɥե饰�Υ��ꥢ���Ѵ������ */
  ADCSR = 0x38 | int_sw | ch_grp; /* ��ư������󥹥����� */
}

void ad_stop(void)
     /* A/D�Ѵ�����ߤ�����ؿ�                  */
     /* �Ѵ���λ�ե饰�򥯥ꥢ�����Ѵ���ߤ����� */
{
  ADCSR = ADCSR & 0x5f;  /* A/D����ɥե饰�Υ��ꥢ, �Ѵ���� */
}
