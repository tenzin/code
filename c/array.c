#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char *my_char[3]; int i,j,k;
  char *append="ilove"; char temp[3][50];
  my_char[0]="sally\n";
  my_char[1]="sara\n";
  my_char[2]="computers\n";
  /*for(i=0;i<3;i++)
  {
    temp=my_char[i];
    printf("%s-%d--temp=%s- fst=%c- %s", append, strlen(append), temp, my_char[i][1],my_char[i]);
  }*/
  my_char[0][0]='X';
  printf("-----------------------------------\n");
  for(i=0;i<3;i++)
  {
    strcpy(temp[i],argv[1]);
    strcat(temp[i], my_char[i]);
    my_char[i]=temp[i];
    printf("%s" , my_char[i]);
  }
  printf("-----------------------------------\n");
  for(i=0;i<3;i++)
  {
    printf("%s" , my_char[i]);
  }
}
