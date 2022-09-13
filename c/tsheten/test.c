#include <stdio.h>
#include <string.h>

int main ()
{
  char str [80];
  float f;
  int d;
  FILE * pFile;
  char *test = "i am tenzin";
  char test1[32];
  strcpy(test1, test);
  printf("%s\n%c\n%s", test, test[0], test1);
  pFile = fopen ("myfile.txt","w+");
  fprintf (pFile, "%f %s\n", 3.1416, "PI");
  fprintf(pFile, "%d %s\n", -23, "NegativeNo");
  rewind (pFile);
  fscanf (pFile, "%f", &f);
  fscanf (pFile, "%s", str);
  printf ("I have read: %f and %s \n",f,str);
  fscanf (pFile, "%d", &d);
  fscanf (pFile, "%s", str);
  printf ("I have read: %d and %s \n",d,str);
  fclose (pFile);
  return 0;
}
