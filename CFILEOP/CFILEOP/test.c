#include <stdio.h>

int main()
{
	FILE* f1 = fopen("file", "w");

	fclose(f1);
	return 0;
}