#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x[3], cnt = 0;
	for (int i = 0; i < 3; i++)
		scanf("%d", x + i);
	while (!(x[1] - x[0] == 1 && x[2] - x[1] == 1))
	{
		if (x[1] - x[0] == 1)
		{
			x[0]++;
			x[1]++;
		}
		else if (x[2] - x[1] == 1)
		{
			x[1]--;
			x[2]--;
		}
		else if (x[1] - x[0] > x[2] - x[1]) //맨 오른쪽 캥거루가 점프
			x[2] = x[1]--;
		else //맨 왼쪽 캥거루가 점프
			x[0] = x[1]++;
		cnt++;

/*		for (int i = 0; i < 3; i++)
		{
			printf("%d", x[i]);
			if (i < 2) printf(" ");
		}
		printf("\n");*/

	}
	printf("%d", cnt);
	//바깥쪽의 두 캥거루 중 가운데 캥거루에 더 가까이 있는 캥거루가 점프해야 함.
	//점프 위치는 x[1]-1 또는 x[1]+1.
	//세 캥거루의 위치가 연속일 때 종료.
}