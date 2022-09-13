#include <stdio.h>

typedef struct
{
  int numerator;
  int denominator;
} fraction;

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
  fraction fr;
  int gcd_val;
  while (scanf("%d %d", &fr.numerator, &fr.denominator) != EOF)
  {
    if (fr.numerator > 0 && fr.denominator > 0)
    {
      gcd_val = gcd(fr.numerator, fr.denominator);
      printf("%d/%d = %d/%d\n", fr.numerator, fr.denominator, fr.numerator/gcd_val, fr.denominator/gcd_val);
    }
  }
  return 0;
}
