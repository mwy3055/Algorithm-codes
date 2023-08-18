#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//void rxSort(int*, int, int, int);
//��� ���� ���� �ʿ� ���� ���̾���

int main()
{
	int n, i;
	scanf("%d", &n);
	int* temp = (int*)malloc(10000 * sizeof(int)); //���� ���� �ִ� 1000�� ȸ ���� �� �����Ƿ� int������ ����

	for (i = 0; i<10000; i++)
		*(temp + i) = 0;

	for (i = 0; i < n; i++)
	{
		int t;
		scanf("%d", &t);
		temp[t - 1]++;
	}

	for (i = 0; i < 10000; i++)
	{
		if (*(temp+i))
		{
			for (int j = 0; j < temp[i]; j++)
				printf("%d\n", i + 1);
		}
	}

	free(temp);
}

/*
* @data  ���� �迭
* @size  data�� �������� ����
* @p  ������ �ִ� �ڸ���
* @k  ���(10������ ����Ѵٸ� 10


void rxSort(int *data, int size, int p, int k) {
	int *counts, // Ư�� �ڸ������� ���ڵ��� ī��Ʈ
		*temp; // ���ĵ� �迭�� ���� �ӽ� ���
	int index, pval, i, j, n;
	counts = (int*)malloc(k * sizeof(int));
	temp = (int*)malloc(size * sizeof(int));
	for (n = 0; n<p; n++) 
	{ // 1�� �ڸ�, 10���ڸ�, 100�� �ڸ� ������ ����
		for (i = 0; i<k; i++)
			counts[i] = 0; // �ʱ�ȭ
						   // ��ġ�� ���.
						   // n:0 => 1,  1 => 10, 2 => 100
		pval = (int)pow((double)k, (double)n);
		// �� ������ �߻�Ƚ���� ����.
		for (j = 0; j<size; j++) 
		{
			// 253�̶�� ���ڶ��
			// n:0 => 3,  1 => 5, 2 => 2
			index = (int)(data[j] / pval) % k;
			counts[index] = counts[index] + 1;
		}
		// ī��Ʈ �������� ���Ѵ�. ��������� ���ؼ�.
		for (i = 1; i<k; i++)
			counts[i] = counts[i] + counts[i - 1];
		// ī��Ʈ�� ����� �� �׸��� ��ġ�� �����Ѵ�.
		// ������� ���
		for (j = size - 1; j >= 0; j--) // �ڿ������� ����
		{ 
			index = (int)(data[j] / pval) % k;
			temp[counts[index] - 1] = data[j];
			counts[index] = counts[index] - 1; // �ش� ���� ī��Ʈ�� 1 ����
		}
		// �ӽ� ������ ����
		memcpy(data, temp, size * sizeof(int));
	}

	free(counts);
	free(temp);
}
*/