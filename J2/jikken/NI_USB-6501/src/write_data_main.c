#include "niusb6501.h"

int main(void)
{ 
  int  i_tmp;
  unsigned char  uc_port;
  unsigned char  uc_data;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  while (1)
  {
    printf("Input port number (0:A port, 1:B port, 2:C port) = ");
    scanf("%d", &i_tmp);
    uc_port = (unsigned char)(i_tmp);
    
    printf("DATA = ");
    scanf("%d", &i_tmp);
    uc_data = (unsigned char)(i_tmp);

    write_port(uc_port, uc_data);    
  }

  return 1;
}
