#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("arg %d = %s\n", i, argv[i]);
		if((!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")))
		{
			printf("Help wanted\n");
		}
	}
	exit(0);
}
