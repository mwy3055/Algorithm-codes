#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

__inline int abs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	int i;
	char s[1001], t[1001];
	short ds[26] = { 0 }, dt[26] = { 0 }, ans = 0;
	scanf("%s %s", s, t);

	for (i = 0; s[i]; i++)
		ds[s[i] - 'a']++;
	for (i = 0; t[i]; i++)
		dt[t[i] - 'a']++;

	for (i = 0; i < 26; i++)
		ans += abs(ds[i] - dt[i]);
	printf("%d", ans);
}