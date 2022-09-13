#include <stdio.h>
#include <stdlib.h>

int main()
{
  float pi_ = 1.0, pi, j, denominator = 3.0;
  int multiplier = -1, i;
  for(i = 2; ; i++)
  {
    j = multiplier * (1 / denominator);
    printf("j = %f\n", j);
    pi_ = pi_ + j;
    printf("PI_ = %f\n", pi_);
    pi = pi_ * 4;
    printf ("PI = %f\n", pi);
    multiplier = multiplier * -1;
    denominator = denominator + 2;
    if(pi > 3.141 && pi < 3.1415)
    {
      printf("PI = %f at iteration %d\n", pi, i);
      break;
    }
  }
  exit(0);
}
