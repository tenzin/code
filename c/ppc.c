#ifdef UNIX
#define SYSTEM 1
#else
#define SYSTEM 0
#endif

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(SYSTEM)
	{
		printf("UNIX\n");
	}
	else
	{
		printf("NON-UNIX\n");
	}
	exit(0);
}
