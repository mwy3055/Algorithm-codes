#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

long long koong[68] = { 1,1,2,4 };

long long calc(int n)
{
	if (koong[n])
		return koong[n];
	else
		return koong[n] = calc(n - 1) + calc(n - 2) + calc(n - 3) + calc(n - 4);

}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", calc(n));
	}
}