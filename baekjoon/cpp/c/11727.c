#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int mem[1005] = { 0 };

int f(int n) //���
{
	if (n == 1)
		return mem[1] = 1;
	else if (n == 2)
		return mem[2] = 3; //1*2�� ������ 2*1�� �� �� �ִ�.
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

//DP�� bottom-up ����?