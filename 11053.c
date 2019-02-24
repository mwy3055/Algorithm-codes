#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int ar[1000], d[1000]; //인덱스=(수-1)

int psearch(int len, int m)//d 길이, m보다 크거나 같은 최소의 위치를 찾음(이분 탐색)
{
	int l = 0, r = len - 1;
	while (1)
	{	
		if (r - l <= 1) //답에 거의 다 왔을 때
		{
			if (d[l] >= m)
				return l;
			else if (d[r] >= m)
				return r;
			else
				return r + 1;
		}
		int mid = (l + r) / 2;
		if (d[mid] < m)
			l = mid + 1;
		else
			r = mid;
	}
}

int lis(int n)
{
	int len = 1, i;
	d[0] = ar[0];
	for (i = 1; i < n; i++)
	{
		int temp = psearch(len, ar[i]); //ar[i]보다 크거나 같은 최초의 위치
		if (len == temp) //맨 뒤에 추가
			d[len++] = ar[i];
		else
			d[temp] = ar[i];
/*		for (j = 0; j < len; j++)
			printf("%d ", d[j]);
		printf("\n");*/
	}
	return len;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", ar + i);
	printf("%d", lis(n));
}