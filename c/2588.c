#include <stdio.h>

#define scanf scanf_s

int main()
{
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	printf("%d\n%d\n%d\n%d", n1*(n2 % 10), n1*((n2 % 100) / 10), n1*(n2 / 100), n1*n2);
	//n2�� ���� �ڸ� ��, ���� �ڸ� ��, ���� �ڸ� ���� n1�� ����
}