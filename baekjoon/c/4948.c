#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prnum(char*, int);

int main()
{
	int m;
	scanf("%d", &m);
	while (m)
	{
		char* num = (char*)calloc(2*m-1, sizeof(int)); //0�̸� �Ҽ�
		prnum(num, m);
		free(num);
		scanf("%d", &m);
	}
}

void prnum(char* num, int m)
{
	int n = 2 * m - 1, count = 0;
	int i, j;
	for (i = 4; i <= n; i += 2) //¦���� ����
		num[i - 1] = 1;
	num[0] = 1; //1�� �Ҽ��� �ƴ�
	for (i = 3; i <= (int)sqrt(n); i += 2) //Ȧ���� �˻�
	{
		if (num[i - 1] == 0)
		{
			for (j = i * i; j <= n; j += i) //i�� ����� ��� �Ҽ��� �ƴ�
				num[j - 1] = 1;
		}
	}
	i = m + 1;
	do
	{
		if (num[i++ - 1] == 0)
			count++;
	} while (i <= n);
	printf("%d\n", count);
}