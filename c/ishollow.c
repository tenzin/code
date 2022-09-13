#include <stdio.h>

int isHollow(int a[], int len)
{
  int pre_nonzero_count=0;
  int foll_nonzero_count=0;
  int zeros_count=0;
  int last_zero_index = -1;
  int i, j;
  int first_zero = 0; /** first zero not found **/

  for(i = 0; i < len; i++)
  {
    if(a[i] == 0)
      break;
    if(a[i] != 0)
      pre_nonzero_count++;
  }

  for(i = 0; i < len; i++)
  {
    if(a[i] == 0 && first_zero == 1)
       zeros_count++;
    if(a[i] == 0 && first_zero == 0) /** first zero found **/
    {
        first_zero = 1;
        zeros_count++;
    }
    if(a[i] != 0 && first_zero == 1)
    {
      last_zero_index = i - 1;
      /** check if there are other zeros after the preceeding numbers **/
      for(j = i+1; j < len; j++)
      {
        if(a[j] == 0)
          return 0;
      }
      break;
    }
  }
  if(last_zero_index == -1 && pre_nonzero_count != 0)
    return 0;
  else
  {
    for(i = last_zero_index + 1; i < len; i++)
    {
      if(a[i] != 0)
        foll_nonzero_count++;
    }
  }
  
  if(pre_nonzero_count == foll_nonzero_count && zeros_count >= 3)
    return 1;
  else
    return 0;
}

int main()
{
  int a1[]={1,2,0,0,0,3,4,0};
  printf("%d\n",isHollow(a1, 8));
}
