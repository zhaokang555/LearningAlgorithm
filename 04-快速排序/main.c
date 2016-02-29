#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quickSort(int arr[], int left, int right)
{
	// 跳出递归的条件
	if (left > right) return;

	int i = left;
	int j = right;
	int base = left;
	while (i < j) {
		// 以arr[left]为基准
		// 顺序很重要，要先从右往左找
		while (arr[j] >= arr[base] && i < j) j--;
		// 再从左往右找
		while (arr[i] <= arr[base] && i < j) i++;

		// 当哨兵i和哨兵j没有相遇时
		// 交换两个数在数组中的位置
		if (i < j)  
			swap(arr, i, j);
	}

	// 最终将基准数归位
	swap(arr, base, i);

	quickSort(arr, left, i - 1); // 继续处理左边的，这里是一个递归的过程
	quickSort(arr, i + 1, right); // 继续处理右边的，这里是一个递归的过程
}

int main(void)
{
	// 输入数据的个数
	int n; 
	printf("Input the number of numbers:\n");
	scanf("%d", &n);

	// 输入数据
	int arr[n];
	printf("Input numbers:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	quickSort(arr, 0, n - 1); // 快速排序调用

	// 输出排序后的结果
	printf("The numbers in ascending order are:\n");
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	system("pause");
	return 0;
}

