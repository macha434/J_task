#include "niusb6501.h"

int main(void)
{
  int time, i_tmp;
  unsigned char  uc_port;
  unsigned char  uc_data;
  unsigned char  uc_data_2;

  init_device();
  set_io_mode(0xFF, 0xFF, 0xFF);

  uc_port = (unsigned char)(0x00);
  
  printf("値を入力してください。 :");
  scanf("%d", &i_tmp);
  
  uc_data = (unsigned char)(i_tmp);

  while (1){
    
    write_port(uc_port, uc_data);
    uc_data = uc_data << 1 | uc_data >> 7;
    sleep(1);
    
  }
  return 1;
}
