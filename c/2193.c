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
	long long a = 1, b = 1, c; //c���
	for (int i = 3; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	printf("%lld", c);
}


//p(1)=1, p(2)=1
//n�ڸ� ��ģ���� ������?
//n>=3�� �� (n-1�ڸ� ��ģ���� ����) + (n-2�ڸ� ��ģ���� ����)
//�ᱹ �Ǻ���ġ ��..