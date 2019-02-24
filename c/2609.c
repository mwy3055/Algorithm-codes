#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int, int);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int gcd = GCD(a, b);
	printf("%d\n%d", gcd, a*b / gcd); //최소공배수:a*b/(최대공약수)
	return 0;
}

int GCD(int a, int b)
{
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b%a)
		return GCD(a, b%a);
	else
		return a;
}