#include <stdio.h>
#include <stdlib.h>
//测试一下怎样传递数组, 下边这两种方式都可以
// void func1(int n, int a[]) 
void func1(int n, int *a)
{
	for(int i = 0; i < n; i++)
		printf("%d\n", a[i]);
}


int main(void)
{
	int b[10];
	for(int i = 0; i < 10; ++i)
		b[i] = i;

	func1(10, b);
	return 0;
}

