#include<stdio.h>
int isPrime(int n)
{
  int half, i;
  half = n / 2;
  for(i=2; i < half+2; i++)
  {
    if(n%i == 0)
      return 0;
  }
  return 1;
}
int isRhinoNumber(int i)
{
  int j, next_number=i;
  if(!isPrime(i))
    return 0;
  if(isPrime(i))
  {
    if(i%10 != 9)
      return 0;
    else
      while(1)
      {
        next_number++;
        if(isPrime(next_number))
        {
          printf("next prime is %d\n", next_number);
           if(next_number%10 == 9)
             return 1;
           else
             return 0;
        }
      }
  } 
}

int main()
{
  printf("%d\n",isRhinoNumber(919));
}
