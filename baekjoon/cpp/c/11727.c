#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int mem[1005] = { 0 };

int f(int n) //재귀
{
	if (n == 1)
		return mem[1] = 1;
	else if (n == 2)
		return mem[2] = 3; //1*2를 돌려서 2*1로 쓸 수 있다.
	else if (mem[n])
		return mem[n];
	else
		return mem[n] = (f(n - 1) + 2 * f(n - 2))%10007;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}

//DP로 bottom-up 가능?