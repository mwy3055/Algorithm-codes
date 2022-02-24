#include <stdio.h>
#include <math.h>

void calc(int d);

int main()
{
	int t, x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &x, &y);
		calc(y - x);
	}
}

void calc(int d)
{
	long long i = 1, temp;
	double diff;
	while (i * i <= d)
		i++;
	i--;										   //i�� d���� ũ�� ���� �ִ��� �������� �����
	temp = d - i * i;							   //�����Ÿ�
	diff = (double)temp / i;					   //i�� double�� �ڵ�����ȯ
	printf("%lld\n", 2 * i - 1 + (int)ceil(diff)); //ceil(a): ���콺 a�� double������ ���
}

//�˰��� ��ó https://www.acmicpc.net/board/view/13747