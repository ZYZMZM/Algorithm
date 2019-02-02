//==================================================================
// Quick Sort
// 作者：ZYZMZM
// 思路：一次划分算法进行分区，可递归或非递归的调用
//==================================================================

#include <stdio.h>

bool IsVaild = true;  // 标志是否为正常输入

int Partition(int *arr, int low, int high)
{
	int temp = arr[low];
	
	while (low < high)
	{
		while (low < high && arr[high] >= temp)  // 一定要注意low < high 这个条件，不能丢
		{
			high--;
		}
		arr[low] = arr[high];

		while (low < high && arr[low] <= temp)
		{
			low++;
		}
		arr[high] = arr[low];
	}

	arr[low] = temp;
	return low;
}

void Quick_Sort(int *arr, int low, int high)
{
	if (arr == NULL || low < 0 || high < 0)
	{
		IsVaild = false;
		return;
	}

	int index = Partition(arr, low, high);

	if (low < index - 1)
	{
		Quick_Sort(arr, low, index - 1);
	}
	if (index + 1 < high)
	{
		Quick_Sort(arr, index + 1 , high);
	}
}

// ====================Test Code====================

void Sort(int *arr, int length)
{
	Quick_Sort(arr, 0 ,length - 1);
	if (IsVaild)
	{
		for (int i = 0; i < length; i++)
		{
			printf("%d  ",arr[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Input is InVaild\n");
	}
}


void Test1()
{
	int arr[] = {3,1,5,4,8,6,9,2,7,0};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test2()
{
	int arr[] = {1,2,3,4,5,9,8,7,6,0};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test3()
{
	int arr[] = {4,3,5,6,7,8,9,0,1,2};
	int length = sizeof(arr)/sizeof(arr[0]);
	Sort(arr,length);
}

void Test4()
{
	int *arr = NULL;
	Sort(arr,0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
}
