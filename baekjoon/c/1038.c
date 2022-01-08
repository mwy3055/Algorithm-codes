#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

typedef long long ll;

ll result;

int fac(int i)
{
	if (i == 0)
		return 1;
	else
	{
		int temp = 1;
		for (int j = 1; j <= i; j++)
		{
			temp *= j;
		}
		return temp;
	}
}
__inline int cmb(int a, int b)
{
	if (a == b) return 1;
	return fac(a) / (fac(b)*fac(a - b));
}
//aCb

void down(int n, int l) //남은 개수, 현재 자릿수
{
	if (l < 0) return;
	else
	{
		int sum = 0, k;
		for (k = l; k <= 9; k++)
		{
			if (sum + cmb(k, l) <= n)
				sum += cmb(k, l);
			else
				break;
		}
		result += ((ll)pow(10, l))*k;
//		printf("added: %lld\n", (ll)pow(10, l)*k);
		down(n - sum, l - 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 10) printf("%d", n);
	else if (n >= 1023) printf("-1");
	else
	{
		int sum = 0, i;
		for (i = 1; i < 10; i++)
		{
			if (sum + cmb(10, i) <= n)
				sum += cmb(10, i);
			else
				break;
		}
		down(n-sum, --i); //i는 가장 자릿수를 나타냄. ex)987의 i는 3
		printf("%lld", result);
	}
}