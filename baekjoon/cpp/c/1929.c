#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//�����佺�׳׽��� ü

int main() 
{
	int m, n;
	int i, j;
	scanf("%d %d", &m, &n);
	char* num = (char*)calloc(n, sizeof(int)); //0�̸� �Ҽ�
	num[0] = 1; //1�� �Ҽ��� �ƴ�

	for (i = 4; i <= n; i += 2) //¦���� ����
		num[i - 1] = 1;

	for (i = 3; i <= (int)sqrt(n); i+=2) //Ȧ���� �˻�
	{
		if (num[i-1] == 0)
		{
			for (j = i * i; j <= n; j += i) //i�� ����� ��� �Ҽ��� �ƴ�
				num[j-1] = 1;
		}
	}
	for (i = m; i <= n; i++)
	{
		if (num[i-1] == 0)
			printf("%d\n", i);
	}
	free(num);
}