/*void sort(int, int, int);
void merge_sort(int, int);

int* num;
int n;

void main()
{
	int i;
	scanf("%d", &n);
	num = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", num + i);

	merge_sort(0, n);
	
	for (i = 0; i < n; i++)
		printf("%d\n", *(num + i));

	free(num);
}

void merge_sort(int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		sort(low, mid, high);
	}
	else
		return;
}

void sort(int low, int mid, int high)
{
	int* sorted = (int*)malloc(n * sizeof(int));
	int n1 = low, n2 = mid + 1, i;

	for (i = low; (n1 <= mid) && (n2 <= high); i++)
	{
		if (*(num + n1) <= *(num + n2))
			*(sorted + i++) = *(num + n1++);
		else
			*(sorted + i++) = *(num + n2++);
	}

	if (n2 == high)
	{
		while (n1 <= mid)
			*(sorted + i++) = *(num + n1++);
	}
	else
	{
		while (n2 <= high)
			*(sorted + i++) = *(num + n2++);
	}

	for (i = low; i <= high; i++)
		*(num + i) = *(sorted + i);

	free(sorted);
}*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* n1, const void* n2) //오름차순 정렬. 내림차순은 1과 -1을 바꾸면 됨
{
	if (*(int*)n1 > *(int*)n2)
		return 1;
	else if (*(int*)n1 < *(int*)n2)
		return -1;
	else
		return 0;
}

int main()
{
	int n, i;
	int* num;
	scanf("%d", &n);
	num = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", num + i);

	qsort(num, n, sizeof(int), compare); //compare:오름차순 또는 내림차순 지정

	for (i = 0; i < n; i++)
		printf("%d\n", *(num + i));

	free(num);
}