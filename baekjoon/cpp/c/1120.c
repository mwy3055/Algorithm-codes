#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
__inline int MIN(int a, int b)
{
	return a < b ? a : b;
}

int diff(char* a, char* b, int start)
{
	int len = strlen(a), cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] != b[start + i])
			cnt++;
	}
	return cnt;
}

int main()
{
	char a[51], b[51];
	scanf("%s %s", a, b);
	int alen = strlen(a), blen = strlen(b), min = 0x7fffffff;
	for (int i = 0; i <= blen - alen; i++) //a�� b�� ���̰� ���� �۾����� ��ġ�� ã��.
		min = MIN(min, diff(a, b, i));
	printf("%d", min);
}