#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;
void psearch(ll,ll,ll,int);
//절단기 높이가 높을수록 얻는 나무의 양이 감소.
//얻고자 하는 나무의 양은 m.
//m보다 나무 양이 크다면 높이를 높여야 한다.

int h[1000000]; //이때 덧셈 연산시에 오버플로우를 방지하기 위해 ll형으로 바꿔야 한다. ll형으로 선언하면 신경쓸 거 없다.

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
		mid = (l + r) / 2; //mid값의 공평한 분배?를 위하여
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