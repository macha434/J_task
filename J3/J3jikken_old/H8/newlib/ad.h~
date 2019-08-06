#define ADSTATUS() (ADCSR & 0x80)
#define ADREAD() ADDRAH
#define ADREAD(0) ADDRAH
#define ADREAD(1) ADDRBH
#define ADREAD(2) ADDRCH
#define ADREAD(3) ADDRDH
#define ADREAD(4) ADDRAH
#define ADREAD(5) ADDRBH
#define ADREAD(6) ADDRCH
#define ADREAD(7) ADDRDH

extern void ad_init();
extern void ad_start(unsigned char ch, unsigned char int_sw);
extern void ad_scan(unsigned char ch_grp, unsigned char int_sw);
extern void ad_stop(void);
