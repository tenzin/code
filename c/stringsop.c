#include <stdio.h>

#define MAKE_STRING(x) #x

int main()
{
  int p = 1;
  char *str;
  str = MAKE_STRING("1");
  printf("%d = %s\n", p, str);
  return 0;
}
