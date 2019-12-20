#include <stdio.h>
#include <termio.h>

char
getchar_sp (void)
{
  struct termio old_term, new_term;
  char c;
  ioctl (0, TCGETA, &old_term);
  new_term = old_term;
  new_term.c_lflag &= ~(ICANON | ECHO);
  ioctl (0, TCSETAW, &new_term);
  c = getchar ();
  ioctl (0, TCSETAW, &old_term);
  return (c);
}
int main(void){
	printf("%c\n",getchar_sp());
return 0;
}	
	
