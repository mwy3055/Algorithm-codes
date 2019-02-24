#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

__inline int maxv(int a, int b)
{
	return a < b ? b : a;
}
__inline int minv(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, max[3] = { 0 }, min[3] = { 0 };
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		int temp[3], num[3];
		scanf("%d %d %d", num, num + 1, num + 2);

		temp[0] = maxv(max[0], max[1]) + num[0];
		temp[1] = maxv(max[0], maxv(max[1], max[2])) + num[1];
		temp[2] = maxv(max[1], max[2]) + num[2];
		memcpy(max, temp, 3 * sizeof(int));

		temp[0] = minv(min[0], min[1]) + num[0];
		temp[1] = minv(min[0], minv(min[1], min[2])) + num[1];
		temp[2] = minv(min[1], min[2]) + num[2];
		memcpy(min, temp, 3 * sizeof(int));
	}

	printf("%d ", maxv(max[0], maxv(max[1], max[2])));
	printf("%d", minv(min[0], minv(min[1], min[2])));
}