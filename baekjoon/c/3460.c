#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void bin(int);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		bin(n);
		printf("\n");
	}
}

void bin(int n)
{
	for (int i = 0; i < 20; i++) //간단
	{
		if (n % 2)
			printf("%d ", i);
		n /= 2;
	}
	/*if (n == 1)
	{
		printf("0");
		return;
	}
	char isone[21] = { 0 };
	int idx = 0, temp;
	while ((int)pow(2, idx) < n)
		idx++;
	if ((int)pow(2,idx) > n)
		idx--;
	temp = idx;
	isone[idx] = 1;
	n -= (int)pow(2, idx--);
	while (1)
	{
		if (n >= (int)pow(2, idx))
		{
			n -= (int)pow(2, idx);
			isone[idx] = 1;
		}
		idx--;
		if (idx == -1)
			break;
	}
	for (int i = 0; i <= temp; i++)
	{
		if (isone[i])
		{
			printf("%d", i);
			if (i < temp)
				printf(" ");
		}
	}*/ //복잡..
}