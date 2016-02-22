#include <stdio.h>
#include <stdlib.h>

void quickSort(int a[], int left, int right)
{
	// 跳出递归的条件
	if (left > right) return;

	int i = left;
	int j = right;
	while (i < j) {
		// 以a[left]为基准
		// 顺序很重要，要先从右往左找
		while (a[j] >= a[left] && i < j) j--;
		// 再从左往右找
		while (a[i] <= a[left] && i < j) i++;

		// 交换两个数在数组中的位置
		if (i < j) { // 当哨兵i和哨兵j没有相遇时
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	// 最终将基准数归位
	int temp = a[left]; 
	a[left] = a[i];
	a[i] = temp;

	quickSort(a, left, i - 1); // 继续处理左边的，这里是一个递归的过程
	quickSort(a, i + 1, right); // 继续处理右边的，这里是一个递归的过程
}

int main(void)
{
	// 输入数据的个数
	int n; 
	printf("Input the number of numbers:\n");
	scanf("%d", &n);

	// 输入数据
	int a[n];
	printf("Input numbers:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	quickSort(a, 0, n - 1); // 快速排序调用

	// 输出排序后的结果
	printf("The numbers in ascending order are:\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", a[i]);

	system("pause");
	return 0;
}

