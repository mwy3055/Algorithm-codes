#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;
void psearch(ll,ll,ll,int);
//���ܱ� ���̰� �������� ��� ������ ���� ����.
//����� �ϴ� ������ ���� m.
//m���� ���� ���� ũ�ٸ� ���̸� ������ �Ѵ�.

int h[1000000]; //�̶� ���� ����ÿ� �����÷ο츦 �����ϱ� ���� ll������ �ٲ�� �Ѵ�. ll������ �����ϸ� �Ű澵 �� ����.

int main()
{
	int n;
	ll m, max = -1, sum = 0;
	scanf("%d %lld", &n, &m);
	for (ll i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		if (max < h[i])
			max = h[i];
	}
	psearch(0, max, m, n);
}

void psearch(ll l,ll r,ll m,int n) 
{
	ll mid, temp = 0;
	if (r - l == 1)
		mid = r;
	else
		mid = (l + r) / 2; //mid���� ������ �й�?�� ���Ͽ�
	for (int i = 0; i < n; i++)
		if (h[i] > mid)
			temp += (ll)h[i] - mid;
	if (l == r)
	{
		if (temp >= m)
			printf("%lld", l);
		else
			printf("%lld", l -1);
	}
	else if (temp >= m)
		psearch(mid, r, m, n);
	else
		psearch(l, mid - 1, m, n);
}