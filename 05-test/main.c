#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char a[101];
	gets(a);

	int len = strlen(a);
	int mid = len / 2 - 1;
	printf("%d %d\n", len, mid);

	system("pause");
	return 0;
}