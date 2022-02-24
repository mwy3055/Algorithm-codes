#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct line {
	int start, end;
} line;

int lis(int start, int n, line* ar) //시작인덱스, ar배열의 원소의 수, ar은 찾을 배열
{
	if (start == n - 1)
		return 1;

	int len = 1, i, d[101] = { 0 };
	d[0] = ar[start].end;
	for (i = start+1; i < n; i++)
	{
		int j = 0;
		while (d[j]<ar[i].end && d[j]) j++;
		if (j == len)
			d[len++] = ar[i].end;
		else
			d[j] = ar[i].end;
	}
	return len; //가장 긴 증가하는 부분 수열의 길이
}

int cmp(const void* a, const void* b)
{
	if (((line*)a)->start > ((line*)b)->start)
		return 1;
	else if (((line*)a)->start < ((line*)b)->start)
		return -1;
	else
		return 0;
}

int main()
{
	int n, i, max = -1;
	scanf("%d", &n);
	line* ln = (line*)calloc(n, sizeof(line));
	for (i = 0; i < n; i++)
		scanf("%d %d", &ln[i].start, &ln[i].end);
	qsort(ln, n, sizeof(line), cmp);
	for (i = 0; i < n; i++)
	{
		int temp = lis(i, n, ln);
		if (max < temp)
			max = temp;
	}







	printf("%d", n - max);
	free(ln);
}