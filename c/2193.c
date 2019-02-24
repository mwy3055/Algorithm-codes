#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//long long

int main()
{
	int n;
	scanf("%d", &n);
	if (n <= 2)
	{
		printf("1");
		return 0;
	}
	long long a = 1, b = 1, c; //c출력
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%lld", c);
}


//p(1)=1, p(2)=1
//n자리 이친수의 개수는?
//n>=3일 때 (n-1자리 이친수의 개수) + (n-2자리 이친수의 개수)
//결국 피보나치 수..