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
	i--;										   //i는 d보다 크지 않은 최대의 제곱수를 만든다
	temp = d - i * i;							   //남은거리
	diff = (double)temp / i;					   //i도 double로 자동형변환
	printf("%lld\n", 2 * i - 1 + (int)ceil(diff)); //ceil(a): 가우스 a를 double형으로 출력
}

//알고리즘 출처 https://www.acmicpc.net/board/view/13747