#include <stdio.h>

void hsort(int*,int);

int main()
{
	int arr[9] = { 7,6,5,8,9,3,4,1,2 };
	hsort(arr,9);
	for (int i = 0; i < 9; i++)
		printf("%d ", *(arr + i));
}

void hsort(int* arr,int size)
{
	int i, temp;
	for (i = 1; i < size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (arr[root] < arr[c])
			{
				temp = arr[c];
				arr[c] = arr[root];
				arr[root] = temp;
			}
			c = root;
		} while (c != 0);
	}
	for (i = size - 1; i >= 0; i--)
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		int root = 0, c = 1;
		do
		{
			c = 2 * root + 1;
			if (c < i - 1 && arr[c] < arr[c + 1])
				c++;
			if (c < i && arr[root] < arr[c])
			{
				temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			root = c;
		} while (c < size);
	}
}