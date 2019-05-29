#include "niusb6501.h"

int main(void)
{ 
  unsigned char  uc_port;
  unsigned char  uc_data;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  while (1)
  {
    printf("Input port number (0:A port, 1:B port, 2:C port) = ");
    scanf("%d", &uc_port);
    
    printf("DATA = ");
    scanf("%d", &uc_data);

    write_port(uc_port, uc_data);    
  }

  return 1;
}
