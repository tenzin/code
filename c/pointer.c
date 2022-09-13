#include <stdio.h>
#include <string.h>

void test(char *st)
{
  printf("Pointer = %p\n", st);
  printf("first char = %c. Length = %d or %d\n", st[0], strlen(st), sizeof(st));
  st[0] = 't';
}

int main()
{
  char stuff[] = {'a', 'b', 'c', '\0'};
  printf("Pointer = %p\n", stuff);
  test(stuff);
  printf("stuff = %s\n", stuff);
  return 0;
}
