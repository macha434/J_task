#include "niusb6501.h"

int main(void)
{
  int time;
  unsigned char  uc_port;
  unsigned char  uc_data;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  uc_port = (unsigned char)(0x00);
  uc_data = (unsigned char)(0xFF);

  for (time= 0; time< 8; time++){
    uc_data = uc_data << 1;
    write_port(uc_port, uc_data);

    sleep(1);
  }
  uc_data = (unsigned char)(0xFF);
  write_port(uc_port, uc_data);

  return 1;
}
