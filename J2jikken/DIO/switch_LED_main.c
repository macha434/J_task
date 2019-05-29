#include "niusb6501.h"

int main(void)
{
  unsigned char  uc_port;
  unsigned char  uc_port2;
  unsigned char  uc_data;
  unsigned char  uc_data2;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  uc_port  = (unsigned char)(0);
  uc_port2  = (unsigned char)(1);
  
  while (1)
  {
    uc_data2 = read_port(uc_port2);
    
    uc_data = uc_data2 >> 1;
    
    write_port(uc_port,uc_data);
  }
  
  return 1;
}
