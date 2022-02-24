#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define minv(a,b) (((a)<(b))?(a):(b))

int chk(int i, char* out)
{
	if (i == 0)
		return out[0] ? 0 : 1;
	for (; i > 0;)
	{
		if (out[i % 10])
			return 0;
		i /= 10;
	}
	return 1;
}

int cipher(int i)
{
	if (i == 0)
		return 1;

	int temp = 0;
	while (i)
	{
		temp++;
		i /= 10;
	}
	return temp;
}

int main()
{
	int n, m, min;
	char out[10] = { 0 }; //�ε���=��, i�� ��ư�� ���峵�� �� out[i]=1
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp); //���峭 ���� ��ư �Է¹���.
		out[temp] = 1;
	}
	//1. +-�θ� �� ���
	min = abs(n - 100); 
	//2. ���ڸ� ������ �� ���
	if (chk(n, out) && cipher(n) < min)
		min = cipher(n);
	//3. N���� ũ�� ��ư�� ������ �� �� �ִ� �ּ��� �ڿ������� -�� �� ���
	for (i = n; i < 900001 && min; i++)
	{
		if (chk(i, out) && cipher(i) + abs(n - i) < min)
		{
			min = cipher(i) + abs(n - i);
			break;
		}
	}
	//4. N���� �۰� ��ư�� ������ �� �� �ִ� �ִ��� �ڿ������� +�� �� ���
	for (i = n - 1; i >= 0 && min; i--)
	{
		if (chk(i, out) && cipher(i) + abs(n - i) < min)
		{
			min = cipher(i) + abs(n - i);
			break;
		}
	}
	printf("%d", min);
}
/* ���� ������ �ڵ�
	int n, m, ntemp = -1000000, count = 0;
	char out[10] = { 0 }; //�ε���=��, i�� ��ư�� ���峵�� �� out[i]=1
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp); //���峭 ���� ��ư �Է¹���.
		out[temp] = 1;
	}
	if (n == 100)
	{
		printf("0");
		return 0;
	}
	for (i = 0; i < 1000000; i++) //ntemp=���峪�� ���� ��ư���� ���� �� �ִ� n�� ���� ����� ��
	{
		if (chk(i, out) && abs(n-i)<abs(n-ntemp))
		{
			ntemp = i;
		}
	}
	if (m == 10)
		printf("%d", abs(n - 100));
	else
		printf("%d", minv(abs(n - ntemp) + cipher(ntemp),abs(n-100)));
*/