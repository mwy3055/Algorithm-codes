#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int istwo(int*);

int main()
{
	int a[3], max = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", a + i);
		if (a[i] > max)
			max = a[i];
	}
	if (a[0] == a[1] && a[1] == a[2])
		printf("%d", 10000 + a[1] * 1000);
	else if (istwo(a))
		printf("%d", 1000 + 100 * istwo(a));
	else
		printf("%d", max * 100);
}

int istwo(int* a)
{
	if (a[0] == a[1] && a[1] != a[2])
		return a[0];
	else if (a[0] == a[2] && a[0] != a[1])
		return a[0];
	else if (a[1] == a[2] && a[1] != a[0])
		return a[1];
	else
		return 0;
}