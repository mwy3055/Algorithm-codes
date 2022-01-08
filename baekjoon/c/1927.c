#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int nd[100001]; //�ε���=��, �� ����� ���� 0

void delete(int);
void mainf();
#define swap(a,b) {int temp=nd[a];nd[a]=nd[b];nd[b]=temp;}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		mainf();
	}
}
void mainf()
{
	int t, idx = 0;
	scanf("%d", &t);
	if (t)
	{
		nd[++idx] = t;
		int i = idx;
		while (i > 1)
		{
			if (nd[i]< nd[i / 2] && nd[i])
				swap(i, i / 2);
			i /= 2;
		}
	}
	else
	{
		printf("%d\n", nd[1]);
		nd[1] = nd[idx];
		nd[idx] = 0;
		if (idx)
			idx--;
		delete(idx);
	}
}

void delete(int idx) //idx:�� �� ��� ��ȣ
{
	int i = 1;
	while (1)
	{
		if (2 * i > idx) //i��° ��尡 �ڽ��� ���� ���� ��
			return;
		if (nd[i * 2] && nd[i * 2 + 1]) //�� �� ���� ���� ��
		{
			if ((nd[i] < nd[i * 2]) && (nd[i] < nd[i * 2 + 1])) //�θ� ���� ���� ��
				return;
			int minidx = nd[i * 2] < nd[i * 2 + 1] ? i * 2 : i * 2 + 1;
			swap(i, minidx);
			i = minidx;
		}
		else if (nd[i * 2] && (nd[i] > nd[i * 2])) //���� �ڽĸ� ���� ��
		{
			swap(i, i * 2);
			i *= 2;
		}
		else //�� �� 0
			return;
	}
}
/*
���� ���� ����

1) ���� ���ο� ��Ұ� ������, �ϴ� ���ο� ��带 ���� ������ ��忡 �̾ ����
2) ���� �Ŀ� ���ο� ��带 �θ����� ��ȯ�ؼ� ���� ������ ����
*/

/*
���� ���� ����

  1) ���� ��Ʈ���� �ְ� ����, �� ������ �ִ� ��带 ��Ʈ ���� �Űܿ´�.
  -> ���� ��������Ʈ���� �����ϴ� �ݸ鿡 ���� ���� �Ӽ��� �ı��ȴ�.
  -> �̸� �����ϱ� ���� �۾��� ���� �ܰ迡������ �����Ѵ�.
  2) �Űܿ� ����� ���� �ڽ��� ���Ͽ� ���� �� �ڽİ� ��ġ ��ȯ�� �Ѵ�.
  (�� ���� �Ӽ��� ���������� �θ� ���� ���� �ڽĺ��� ���� ���� ������ �ϱ� ����)
  3) �Űܿ� ��尡 �� �̻� �ڽ��� ���� �ٳ�尡 �ǰų� ���� �ڽĺ��� ���� ���� ���� ��쿡�� ���� ������ �����Ѵ�.
  �׷��� ���� ��쿡�� �ܰ�2�� �ݺ��Ѵ�.

*/
