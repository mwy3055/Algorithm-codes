#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

int arr[1001][10]; //�ε���=��
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

//i�ڸ� ������ ���� i-1��° �ڸ��� ���ڰ� j ��� ���� �� �� ������ i-1 �ڸ����� ���ڸ��� j ���� ũ�ų� ���� ������ ���� �� �ִ�.