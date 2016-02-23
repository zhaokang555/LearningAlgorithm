#include <stdio.h>
#include <stdlib.h>

// 传入数组的首地址和数组元素的个数
void bubbleSort(int a[], int n)
{
	// 冒泡排序的核心部分
	for(int i = 1; i <= n-1; i++) //n个数排序，只用进行n-1趟
	{
		// 从第1位开始比较直到最后一个尚未归位的数，
		// 想一想为什么到n-i就可以了。
		for(int j = 1; j <= n-i; j++)  
		{ 
			if(a[j-1] > a[j]) // 比较大小并交换
			{ 
				int temp = a[j-1]; 
				a[j-1] = a[j]; 
				a[j] = temp; 
			}
		}
	}
}

int main(void)
{
	int a[5];
	printf("%s\n", "Input 5 numbers:\n");
	for(int i = 0; i <= 4; i++)
		scanf("%d", &a[i]);

	bubbleSort(a, 5);

	printf("%s\n", "The results in ascending order is:\n");
	for(int i = 0; i <= 4; i++)
		printf("%d\n", a[i]);

	system("pause");
}

