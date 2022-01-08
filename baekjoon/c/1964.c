#include <stdio.h>

#define scanf scanf_s
typedef unsigned long long ull;
int main()
{
	ull n;
	scanf("%lld", &n);
	printf("%lld", (n + 1)*(3 * n + 2) / 2 % 45678); //노트에 식 있음
}