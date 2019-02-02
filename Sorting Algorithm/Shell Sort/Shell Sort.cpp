//==================================================================
// Shell Sort
// 作者：ZYZMZM
// 思路：基于选择排序，是一种优化算法，取决于所取的增量序列gap
//==================================================================

#include <stdio.h>

bool IsVaild = false;  // 标志是否为正常输入

void Shell_Sort(int *arr, int length)
{
	IsVaild = false;

	if (arr == NULL || length <= 0)
	{
		return;
	}

	for (int gap = length / 2; gap >= 1; gap /= 2)
	{
		for (int i = gap; i < length; i++)
		{
			int j = i - gap;
			int temp = arr[i];
			while (j >= 0 && arr[j] > temp)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = temp;
		}
	}
	
	IsVaild = true;
}

// ====================Test Code====================

void Sort(int *arr, int length)
{
	Shell_Sort(arr,length);
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
	int arr[] = {3,1,5,2,7,6,9,3,7,0};
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
