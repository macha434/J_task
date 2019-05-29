#include "niusb6501.h"

int main(void)
{ 
  unsigned char  uc_port;
  unsigned char  uc_data;

  init_device();
  set_io_mode(0x00, 0x00, 0x00);

  while (1)
  {
    for (uc_port = 0;  uc_port < 3;  uc_port++)
    {
      uc_data = read_port(uc_port);
      switch (uc_port)
      {
      case 0: 
	printf("port A = %X ", uc_data);
	break;
      case 1:
	printf("port B = %X ", uc_data);
	break;
      case 2:
	printf("port C = %X ", uc_data);
	break;
      default:
	printf("ERROR !\n");
      }
    }
    printf("\r");
    fflush(NULL);
  }

  return 1;
}
