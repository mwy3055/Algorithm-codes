#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000000
#include <stdio.h>
int arr[101][10]; //ÀÎµ¦½º=¼ö
int sum(int*);

int main()
{
	int n;
	scanf("%d", &n);
	arr[0][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i == 1)
				arr[i][j] = 1;
			else if (j == 1)
				arr[i][j] = (arr[i - 2][1] + arr[i - 1][2]) % mod;
			else if (j == 9)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 1; i <= 9; i++)
		printf("%d ", arr[n][i]);
	printf("\n%d", sum(arr[n]));
}

int sum(int* ar)
{
	int s = 0;
	for (int i = 1; i <= 9; i++)
		s = (s + ar[i]) % mod;
	return s;
}