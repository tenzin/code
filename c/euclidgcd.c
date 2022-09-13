#include <stdio.h>

int gcd(int u, int v)
{
  int t, counter = 0;
  while (u > 0)
  {
    if (u < v)
    {
      t = u;
      u = v;
      v = t;
    }
    u = u % v;
    counter++;
  }
  printf("looped %d times\n", counter);
  return v;
}

int main()
{
  int x, y;
  while (scanf("%d %d", &x, &y) != EOF)
  {
    if (x > 0 && y > 0)
      printf("%d %d %d\n", x, y, gcd(x, y));
  }
  return 0;
}
