#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x[3], cnt = 0;
	for (int i = 0; i < 3; i++)
		scanf("%d", x + i);
	while (!(x[1] - x[0] == 1 && x[2] - x[1] == 1))
	{
		if (x[1] - x[0] == 1)
		{
			x[0]++;
			x[1]++;
		}
		else if (x[2] - x[1] == 1)
		{
			x[1]--;
			x[2]--;
		}
		else if (x[1] - x[0] > x[2] - x[1]) //�� ������ Ļ�ŷ簡 ����
			x[2] = x[1]--;
		else //�� ���� Ļ�ŷ簡 ����
			x[0] = x[1]++;
		cnt++;

/*		for (int i = 0; i < 3; i++)
		{
			printf("%d", x[i]);
			if (i < 2) printf(" ");
		}
		printf("\n");*/

	}
	printf("%d", cnt);
	//�ٱ����� �� Ļ�ŷ� �� ��� Ļ�ŷ翡 �� ������ �ִ� Ļ�ŷ簡 �����ؾ� ��.
	//���� ��ġ�� x[1]-1 �Ǵ� x[1]+1.
	//�� Ļ�ŷ��� ��ġ�� ������ �� ����.
}