#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int ar[1000], d[1000]; //�ε���=(��-1)

int psearch(int len, int m)//d ����, m���� ũ�ų� ���� �ּ��� ��ġ�� ã��(�̺� Ž��)
{
	int l = 0, r = len - 1;
	while (1)
	{	
		if (r - l <= 1) //�信 ���� �� ���� ��
		{
			if (d[l] >= m)
				return l;
			else if (d[r] >= m)
				return r;
			else
				return r + 1;
		}
		int mid = (l + r) / 2;
		if (d[mid] < m)
			l = mid + 1;
		else
			r = mid;
	}
}

int lis(int n)
{
	int len = 1, i;
	d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int temp = psearch(len, ar[i]); //ar[i]���� ũ�ų� ���� ������ ��ġ
		if (len == temp) //�� �ڿ� �߰�
			d[len++] = ar[i];
		else
			d[temp] = ar[i];
/*		for (j = 0; j < len; j++)
			printf("%d ", d[j]);
		printf("\n");*/
	}
	return len;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);
	printf("%d", lis(n));
}