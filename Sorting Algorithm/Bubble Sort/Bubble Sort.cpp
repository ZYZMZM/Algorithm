//==================================================================
// Bubble Sort
// 作者：ZYZMZM
// 思路：两两比较，大数冒泡至尾部
//==================================================================

#include <stdio.h>

bool IsVaild = false;  // 标志是否为正常输入

void Bubble_Sort(int *arr, int length)
{
	IsVaild = false;

	if (arr == NULL || length <= 0)
	{
		return;
	}

	bool IsSwap = false;

	for (int i = 0; i < length; i++)
	{
		IsSwap = false;
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])  // 两两比较
			{
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				IsSwap = true;
			}
		}

		if (IsSwap == false)
		{
			break;
		}
	}
	IsVaild = true;
}

// ====================Test Code====================

void Sort(int *arr, int length)
{
	Bubble_Sort(arr,length);
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
