#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmp(int*, int*);
void hsort(int*, int);

int main()
{
	int n, m, temp, i;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		*(arr + i) = temp;
	}
	hsort(arr, n); //힙소트
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &temp);
		void* search = bsearch(&temp, arr, n, sizeof(int), cmp);
		if (search == NULL)
			puts("0");
		else
			puts("1");
	}
	free(arr);
}

int cmp(int* a, int* b) { //return이 1이면 좌우를 바꾸고 -1이면 바꾸지 않음. 이건 오름차순
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}
void hsort(int* arr, int size)
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