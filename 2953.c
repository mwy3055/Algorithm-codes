#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a[5][4], max = 0, maxl = 0;
	for (int i = 0; i < 5; i++)
	{
		int temp = 0;
		for (int j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
			temp += a[i][j];
		}
		if (max < temp)
		{
			max = temp;
			maxl = i + 1; //번호=라인+1
		}
	}
	printf("%d %d", maxl, max);
}