#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k, len = 0;
	int i = 1, j, l;
	scanf("%d", &k);

	while ((1<<i) - 2 < k) //2�� n������ 1<<n
	{
		i++;
		len++;
	}
	l = len - 1; //�ε���
	char* str = (char*)calloc(len + 1, sizeof(char));
	int nth = k - (1<<len) +1;

	//nth�� ��������
	while (nth)
	{
		str[l--] = nth % 2;
		nth /= 2;
	}

	for (j = 0; j < len; j++)
		printf("%d", str[j] ? 7 : 4);

	free(str);
}
//k�� �������� �ٲٸ� �ȴ�. �ٸ� �̷��� �ϸ� ����� ���̸� ���� �˾ƾ߰���.
