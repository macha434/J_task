#include "niusb6501.h"

int main(void)
{ 
  unsigned char  uc_port;
  unsigned char  uc_data;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  uc_port = (unsigned char)(0x00);

  while (1)
  { 
    uc_data = (unsigned char)(0x00);
    write_port(uc_port, uc_data);

    sleep(1);

    uc_data = (unsigned char)(0xFF);
    write_port(uc_port, uc_data);

    sleep(1);
  }

  return 1;
}
