#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[31]; //인덱스=수

int dp(int p)
{
	if (p == 0)
		return 1; //ar[0]=1 (아무것도 안 한 상태..)
	else if (p == 1)
		return 0;
	else if (p == 2)
		return 3;
	else if (ar[p] != 0)
		return ar[p];

	int temp = 3 * dp(p - 2);
	for (int i = 4; i <= p; i += 2)
		temp += 2 * dp(p - i); //p-4 p-6 ... 0까지
	return ar[p] = temp;
}

int main()
{
	int n; 
	scanf("%d", &n);
	printf("%d", dp(n));
}