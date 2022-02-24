#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void psearch(char*, int);
void gbpart(char*, int);
int cmp(const void*, const void*);

int main() //옛 코드
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		char* pr = (char*)calloc(n, sizeof(char));
		psearch(pr, n);
		gbpart(pr, n);
		free(pr);
	}
}

void psearch(char* pr, int n)
{
	int i, j;
	pr[0] = 1; //1은 소수가 아님
	for (i = 4; i <= n; i += 2) //짝수는 빼고
		pr[i - 1] = 1;
	for (i = 3; i <= (int)sqrt(n); i += 2) //홀수만 검사
	{
		if (pr[i - 1] == 0)
		{
			for (j = i * i; j <= n; j += i) //i의 배수는 모두 소수가 아님
				pr[j - 1] = 1;
		}
	}
}

void gbpart(char* pr, int n)
{
	int mid, sm = 0, lg = 0, pt1 = -(n*n), pt2 = n * n;
	int i, j = 0; //인덱스
	for (i = 0; i <= n / 2 - 1; i++)
	{
		if (pr[i] == 0)
			sm++;
	}
	int* smpr = (int*)calloc(sm,sizeof(int));
	for (i = 0; i <= n / 2 - 1; i++)
	{
		if (pr[i] == 0)
			smpr[j++] = i + 1;
	}

	if (pr[n / 2 - 1] == 0) mid = n / 2 - 1; //mid는 인덱스
	else mid = n / 2;

	for (i = mid; i < n; i++)
	{
		if (pr[i] == 0)
			lg++;
	}
	int* lgpr = (int*)calloc(lg,sizeof(int));
	for (i = mid, j = 0; i < n; i++)
	{
		if (pr[i] == 0)
			lgpr[j++] = i + 1;
	}
	for (i = 0; i < sm; i++)
	{
		int key = n - smpr[i];
		void *tp = bsearch(&key, lgpr, lg, sizeof(int), cmp);
		if ((tp != NULL) && (key - smpr[i]<pt2 - pt1))
		{
			pt1 = smpr[i];
			pt2 = key;
		}
	}

	printf("%d %d\n", pt1, pt2);

	free(smpr);
	free(lgpr);
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

//간단 풀이
/*
int main()
{
	char che[10001] = { 1, 1 }; //인덱스 1번부터 시작, 0이면 소수
	int i, j, t;
	for (i = 2; i < (int)sqrt(10000); i++)
		if (che[i] == 0)
			for (j = i * 2; j < 10000; j += i)
				che[j] = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (i = n / 2; i > 0; i--)
			if (che[i] == 0 && che[n - i] == 0) 
				break;
		printf("%d %d\n", i, n - i);
	}
}
*/