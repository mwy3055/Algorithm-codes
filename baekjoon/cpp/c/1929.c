#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//에라토스테네스의 체

int main() 
{
	int m, n;
	int i, j;
	scanf("%d %d", &m, &n);
	char* num = (char*)calloc(n, sizeof(int)); //0이면 소수
	num[0] = 1; //1은 소수가 아님

	for (i = 4; i <= n; i += 2) //짝수는 빼고
		num[i - 1] = 1;

	for (i = 3; i <= (int)sqrt(n); i+=2) //홀수만 검사
	{
		if (num[i-1] == 0)
		{
			for (j = i * i; j <= n; j += i) //i의 배수는 모두 소수가 아님
				num[j-1] = 1;
		}
	}
	for (i = m; i <= n; i++)
	{
		if (num[i-1] == 0)
			printf("%d\n", i);
	}
	free(num);
}