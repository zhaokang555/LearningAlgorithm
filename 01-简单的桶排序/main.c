#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[11];
	for(int i = 0; i <= 10; i++) 
		a[i] = 0;
		
	int temp = 0;
	for(int i = 1; i <= 5; i++)
	{
		scanf("%d", &temp);
		a[temp] += 1;
	}
	
	printf("result:\n");
	for(int i = 0; i <= 10; i++)
	{
		for(int j = 1; j <= a[i]; j++)
			printf("%d\n", i);
	}
	
	system("pause");
	return 0;
}
