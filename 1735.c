#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct div {
	int son, mom;
} div;

int GCD(int a, int b) //최대공약수. 최소공배수=(a*b/GCD)
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

int main()
{
	int temp;
	div n1, n2;
	scanf("%d %d %d %d", &n1.son, &n1.mom, &n2.son, &n2.mom);
	int momgcd = n1.mom*n2.mom / GCD(n1.mom, n2.mom);
	if (n1.mom != momgcd)
		n1.son *= (momgcd / n1.mom);
	if (n2.mom != momgcd)
		n2.son *= (momgcd / n2.mom);

	div rst = { n1.son + n2.son,momgcd };
	if (1 != (temp = GCD(rst.son, rst.mom)))
	{
		rst.son /= temp;
		rst.mom /= temp;
	}
	printf("%d %d", rst.son, rst.mom);
}