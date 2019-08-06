#include <stdio.h>
#include <string.h>

int my_strlen1(const char str[])
{
  int ct;
  
  ct = 0;
  while (str[ct] != '\0') {
    ct++;
  }

  return ct;
}

int my_strlen2(char *str)
{
  int ct;
  
  ct = 0;
  while (*(str++) != '\0') {
    ct++;
  }

  return ct;
}

int my_strlen3(char *str)
{
  char *p;

  p = str;

  while (*str) {
    str++;
  }
  
  return str-p;
}

int my_strlen4(char *str)
{
  char *p;

  p = str;

  while (*(++str));
  
  return str-p;
}

int main(void)
{
  char mojiretsu[] = "kisarazu";
  int len;

  printf("%s\n", mojiretsu);
  
  len = my_strlen1(mojiretsu);
  printf("my_strlen1=%d\n", len);
  printf("%s\n", mojiretsu);

  len = my_strlen2(mojiretsu);
  printf("my_strlen2=%d\n", len);
  
  len = my_strlen3(mojiretsu);
  printf("my_strlen3=%d\n", len);
  
  len = my_strlen4(mojiretsu);
  printf("my_strlen4=%d\n", len);
  
  len = strlen(mojiretsu);
  printf("strlen=%d\n", len);

  return 0;
}
