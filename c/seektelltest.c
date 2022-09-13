#include<stdio.h>

int main()
{
  int data, i;
  char cdata;
  FILE *f1;
  long track;
  f1 = fopen("testfile", "r");
  for (i = 0; i < 2; i++)
  {
    fscanf(f1, "%d %c", &data, &cdata);
    printf("data = %d %c\n", data, cdata);
  }
  track = ftell(f1);
  for (i = 0; i < 2; i++)
  {
    fscanf(f1, "%d %c", &data, &cdata);
    printf("data = %d %c\n", data, cdata);
  }
  fseek(f1, track, SEEK_SET);
  for (i = 0; i < 2; i++)
  {
    fscanf(f1, "%d %c", &data, &cdata);
    printf("data = %d %c\n", data, cdata);
  }
  fclose(f1);
  return 0;
}
