#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct {
	int roll;
	char *name;
} info;

int main(int argc, char *argv[])
{
	info info_me;
	printf("std_in = %d\nstd_out = %d\nstd_err = %d\n", STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	info_me.roll=40;
	info_me.name="tenzin";
	printf("Roll = %d\nName = %s\n", info_me.roll, info_me.name);
	exit(0);
}
