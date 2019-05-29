#include "niusb6501.h"

int main(void)
{ 
  unsigned char  uc_port=0;
  unsigned char  uc_data, uc_data2;

  init_device();
  set_io_mode(0x00, 0x00, 0x00);

  while (1)
  {
     uc_data = read_port(uc_port);
     printf("port A = %X ", uc_data);
     write_data(1)
   }
    printf("\r");
    fflush(NULL);
  }

  return 1;
}
