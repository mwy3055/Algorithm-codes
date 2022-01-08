#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pm(int);

int main()
{
	int n, i, temp, count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		count+= pm(temp);
	}
	printf("%d", count);
}

int pm(int n)
{
	int i;
	if (n == 1) //1은 소수가 아니지
		return 0;
	else
	{
		for (i = 2; i <= (int)sqrt(n); i++)
		{
			if (n%i == 0)
				return 0;
		}
		return 1;
	}
}