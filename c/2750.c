#include <stdio.h>
#include <stdlib.h>

void insert_sort(int*,int);

int main() 
{
	int n, i = 0, *num;

	scanf("%d", &n);
	num = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", num + i);

	insert_sort(num,n);

	free(num);
}

void insert_sort(int* num,int n) 
{
	int i, j, temp;

	for (i = 0; i < n-1; i++)
	{
		for (j = 1; j < n-i ; j++)
		{
			if (num[j-1] > num[j])
			{
				temp = num[j-1];
				num[j-1] = num[j];
				num[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d\n", num[i]);
}