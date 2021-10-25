#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *p = malloc(sizeof(int));
	*p = 1;
	printf("%d %d", getpid(), *p);
	return 0;
}