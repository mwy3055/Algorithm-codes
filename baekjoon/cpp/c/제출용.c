#include <stdio.h>
#include <math.h>

int main() //�Ҽ� ���ϴ� �� �� ���� �ɸ��ٴµ�..
{
	char check[1000002] = { 0 }; //���� ���� ��:0
	long long min, max, cnt = 0, sq, r;
	long long i, j;
	scanf("%lld %lld", &min, &max);
	r = sqrt(max); //������ ����
	for (i = 2; i <= r; i++)
	{
		sq = i * i;
		j = ceil((double)min / sq)*sq; //�������� �����ϰ� ����
		for (; j <= max; j += sq) //�������� ������ �������� ���� �Ÿ���.
			check[j - min] = 1; //���� ���� ��
	}
	for (i = min; i <= max; i++)
		if (check[i - min])
			cnt++; //���� ���� ���� ���� ��
	printf("%lld", max - min + 1 - cnt);
}