#include <stdio.h>
#include <math.h>

int main() //소수 구하는 게 더 오래 걸린다는데..
{
	char check[1000002] = { 0 }; //제곱 ㄴㄴ 수:0
	long long min, max, cnt = 0, sq, r;
	long long i, j;
	scanf("%lld %lld", &min, &max);
	r = sqrt(max); //제곱할 범위
	for (i = 2; i <= r; i++)
	{
		sq = i * i;
		j = ceil((double)min / sq)*sq; //시작점을 엄밀하게 구함
		for (; j <= max; j += sq) //제곱수로 나누어 떨어지는 수를 거르자.
			check[j - min] = 1; //제곱 ㅇㅇ 수
	}
	for (i = min; i <= max; i++)
		if (check[i - min])
			cnt++; //제곱 ㅇㅇ 수의 개수 셈
	printf("%lld", max - min + 1 - cnt);
}