#include <stdio.h>

int main()
{
	int a, b, v;
	scanf_s("%d %d %d", &a, &b, &v);
	printf("%d", (v - b - 1) / (a - b) + 1); //(v-b)�� �ӷ� (a-b)�� �ö󰡴� �� �ɸ��� �ð�?
}