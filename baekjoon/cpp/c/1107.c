#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define minv(a,b) (((a)<(b))?(a):(b))

int chk(int i, char* out)
{
	if (i == 0)
		return out[0] ? 0 : 1;
	for (; i > 0;)
	{
		if (out[i % 10])
			return 0;
		i /= 10;
	}
	return 1;
}

int cipher(int i)
{
	if (i == 0)
		return 1;

	int temp = 0;
	while (i)
	{
		temp++;
		i /= 10;
	}
	return temp;
}

int main()
{
	int n, m, min;
	char out[10] = { 0 }; //인덱스=수, i번 버튼이 고장났을 때 out[i]=1
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp); //고장난 숫자 버튼 입력받음.
		out[temp] = 1;
	}
	//1. +-로만 갈 경우
	min = abs(n - 100); 
	//2. 숫자만 눌러서 갈 경우
	if (chk(n, out) && cipher(n) < min)
		min = cipher(n);
	//3. N보다 크고 버튼을 눌러서 갈 수 있는 최소의 자연수에서 -로 갈 경우
	for (i = n; i < 900001 && min; i++)
	{
		if (chk(i, out) && cipher(i) + abs(n - i) < min)
		{
			min = cipher(i) + abs(n - i);
			break;
		}
	}
	//4. N보다 작고 버튼을 눌러서 갈 수 있는 최대의 자연수에서 +로 갈 경우
	for (i = n - 1; i >= 0 && min; i--)
	{
		if (chk(i, out) && cipher(i) + abs(n - i) < min)
		{
			min = cipher(i) + abs(n - i);
			break;
		}
	}
	printf("%d", min);
}
/* 가장 무식한 코드
	int n, m, ntemp = -1000000, count = 0;
	char out[10] = { 0 }; //인덱스=수, i번 버튼이 고장났을 때 out[i]=1
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp); //고장난 숫자 버튼 입력받음.
		out[temp] = 1;
	}
	if (n == 100)
	{
		printf("0");
		return 0;
	}
	for (i = 0; i < 1000000; i++) //ntemp=고장나지 않은 버튼으로 만들 수 있는 n과 가장 가까운 수
	{
		if (chk(i, out) && abs(n-i)<abs(n-ntemp))
		{
			ntemp = i;
		}
	}
	if (m == 10)
		printf("%d", abs(n - 100));
	else
		printf("%d", minv(abs(n - ntemp) + cipher(ntemp),abs(n-100)));
*/