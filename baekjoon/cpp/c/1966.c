#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct document {
	char sc; //�����ϴ� �����ΰ�?
	int pri; //�켱��
} doc;

void printq(doc*,int);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m, i; //m�� �ε���
		scanf("%d %d", &n, &m);
		doc* q = (doc*)calloc(n, sizeof(doc));
		q[m].sc = 1;
		for (i = 0; i < n; i++)
			scanf("%d", &q[i].pri);
		printq(q,n);
		free(q);
	}
}

void printq(doc* q,int n)
{
	int prcnt = 0, idx = 0; //�μ���� ���� ���� �� ����
	int i;
	while (1)
	{
		int dobr = 0;
		if (n == 1)
		{
			puts("1");
			return;
		}
		for (i = idx + 1; i < n; i++)
		{
			if (q[idx].pri < q[i].pri)
			{
				doc temp;
				memcpy(&temp, &q[idx], sizeof(doc));
				for (i = idx; i < n - 1; i++)
					memcpy(&q[i], &q[i + 1], sizeof(doc));
				memcpy(&q[n - 1], &temp, sizeof(doc));
				dobr = 1;
				break;
			}
		}
		if (dobr)
			continue;
		prcnt++;
		if (q[idx].sc == 1)
		{
				printf("%d\n", prcnt);
			return;
		}
		idx++;
	}
}