#include "h8-3052-iodef.h"

#define INTERVAL		1000

#define SCI_TDRE		0x80
#define SCI_RDRF		0x40
#define SCI_BRK			0x20
#define SCI_FER			0x10
#define SCI_PER			0x08

#define SCI_RDRF_CLEAR		0xBC
#define SCI_TDRE_CLEAR		0x78
#define SCI_ERROR_CLEAR		0xC4

void handleError(void)
{
  SSR0 = SCI_ERROR_CLEAR;
}

void init_serial(void)
{
  int i;

  SCR0 = 0x00;		/* TE/RE CLEAR */  
  SMR0 = 0x00;		/* ASYNC 8 BIT, NON PARITY, 1 STOP BIT */
  //  BRR0 = 10;		/* 57600 BPS */
  BRR0 = 19;            /*   8bit,non-parity,1-stop,38400bps[φ=25MHz] */
  //  BRR0 = 32;		/* 19200 BPS */
  i = INTERVAL;
  while (i--);		/* WAIT 1 BIT CYCLE */
  SCR0 = 0x70;		/* RIE/TE/RE SET */
}

static inline int getDebugCharReady(void)
{
  unsigned char status;

  status = SSR0;
  if (status & (SCI_PER | SCI_FER | SCI_BRK))	/* ERROR ? */
    handleError ();

  return (status & SCI_RDRF);
}

char getDebugChar(void)
{
  unsigned char status;
  char ch;

  while ( ! getDebugCharReady());

  ch = RDR0;
  status = SSR0;
  SSR0 = SCI_RDRF_CLEAR; 

  if (status & (SCI_PER | SCI_FER | SCI_BRK))	/* ERROR ? */
    handleError ();

  return ch;
}

static inline int putDebugCharReady(void)
{
  unsigned char status;

  status = SSR0;
  return (status & SCI_TDRE);
}

void putDebugChar(char ch)
{
    
  while (!putDebugCharReady());

  TDR0 = ch;
  SSR0 = SCI_TDRE_CLEAR;
}
