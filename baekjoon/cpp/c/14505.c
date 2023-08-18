#define _CRT_SECURE_NO_WARNINGS

//부분집합 수는 (int)pow(2,strlen(str))-1
//한 글자로 구성된 부분집합은 팰린드롬
#include <stdio.h>
#include <string.h>

int memoi[30][30];

int dp(int s, int r, char* str)
{
	if (s > r) return 0;
	else if (s == r) return 1;
	else if (memoi[s][r]) return memoi[s][r];

	if (str[s] == str[r])
		return memoi[s][r] = dp(s + 1, r, str) + dp(s, r - 1, str) + 1;
	else
		return memoi[s][r] = dp(s + 1, r, str) + dp(s, r - 1, str) - dp(s + 1, r - 1, str);
}

int main()
{
	char s[31];
	gets(s);
	printf("%d", dp(0, (int)strlen(s) - 1, s));
}