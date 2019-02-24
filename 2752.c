#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void*, const void*);

int main()
{
	int a[3], i;
	for (i = 0; i < 3; i++)
		scanf("%d", a + i);
	qsort(a, 3, sizeof(int), compare);
	printf("%d %d %d", *a, *(a + 1), *(a + 2));
}
int compare(const void* n1, const void* n2) //오름차순 정렬
{
	if (*(int*)n1 > *(int*)n2)
		return 1;
	else if (*(int*)n1 < *(int*)n2)
		return -1;
	else
		return 0;
}