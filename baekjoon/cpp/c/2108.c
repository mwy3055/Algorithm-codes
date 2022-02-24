#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void arithmean(int*,int);
void midvalue(int*,int);
int compare(const void*, const void*);
void common(int*,int);
void range(int*,int);

int main()
{
	int n;
	scanf("%d", &n);
	int *num = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", num + i);
	arithmean(num, n);
	midvalue(num, n);
	common(num, n);
	range(num, n);

	free(num);
}

void arithmean(int* num,int n)
{
	int sum = 0;
	if (n == 1) sum = *num;
	else
	{
		for (int i = 0; i < n; i++)
			sum += *(num + i);
	}
	double avg = (double)sum / n;
	printf("%d\n", (int)floor(avg + 0.5)); //floor는 내림함수, 0.5를 더해서 내림
}

void midvalue(int* num, int n)
{
	qsort(num, n, sizeof(int), compare);
	printf("%d\n", *(num + (n - 1) / 2));
}

int compare(const void* n1, const void* n2)
{
	if (*(int*)n1 > *(int*)n2)
		return 1;
	else if (*(int*)n1 < *(int*)n2)
		return -1;
	else
		return 0;
}

void common(int* num, int n)
{
	int count = 1, idx = 0, kind = 0, i, temp = 1;
	int cmindex = 0, cmvalue = 0; //최빈값 인덱스, 최빈값
	for (i = 0; i < n - 1; i++)
	{
		if (num[i] == num[i + 1])
			count++;
		if ((num[i] != num[i + 1]) || (i == n - 2))
		{
			if (count > cmvalue)
			{
				cmindex = i;
				cmvalue = count;
				temp = 1;
			}
			else if (count == cmvalue)
			{
				temp++;
				if (temp == 2)
					cmindex = i;
			}
			count = 1;
		}
	}
	printf("%d\n", num[cmindex]);
}

void range(int* num, int n)
{
	printf("%d\n", num[n - 1] - num[0]); //정렬이 되어있기 때문에 (끝값)-(처음값)이 범위이다.
}