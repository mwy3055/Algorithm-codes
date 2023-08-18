#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

int arr[1001][10]; //인덱스=수
int sum(int*,int);

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1)
				arr[i][j] = 1;
			else
				arr[i][j] = sum(arr[i - 1], j);
		}
	}
	printf("%d", sum(arr[n], 0));
}

int sum(int* ar, int j)
{
	int s = 0;
	for (int i = j; i <= 9; i++)
		s = (s + ar[i]) % 10007;
	return s;
}

//i자리 오르막 수의 i-1번째 자리의 숫자가 j 라고 했을 때 총 개수는 i-1 자릿수의 앞자리가 j 보다 크거나 같은 값으로 만들 수 있다.