#include <stdio.h>

int main()
{
	int a, b, v;
	scanf_s("%d %d %d", &a, &b, &v);
	printf("%d", (v - b - 1) / (a - b) + 1); //(v-b)를 속력 (a-b)로 올라가는 데 걸리는 시간?
}