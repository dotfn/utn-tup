// utils.c
#include <stdio.h>

void cleanBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}
