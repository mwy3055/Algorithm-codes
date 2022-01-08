#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum = 0, ang[3], same = 0;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", ang+i);
		sum += *(ang + i);
	}
	if (sum != 180)
	{
		printf("Error");
		return 0;
	}
	if (ang[0] == ang[1]) same++;
	if (ang[1] == ang[2]) same++;
	if (ang[0] == ang[2]) same++;
	switch (same)
	{
	case 0:
		printf("Scalene");
		break;
	case 1:
		printf("Isosceles");
		break;
	default: //case 3
		printf("Equilateral");
		break;
	}
}