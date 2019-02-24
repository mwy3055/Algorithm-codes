#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct string {
	char str[51];
	int len;
} string;

int compare(string*,string*);

int main()
{
	int n, i;
	scanf("%d", &n);
	string* st = (string*)calloc(n, sizeof(string));
	for (i = 0; i < n; i++)
	{
		scanf("%s", st[i].str);
		st[i].len = (int)strlen(st[i].str);
	}
	qsort(st, n, sizeof(string), compare); //개꿀

	for (i = 0; i < n; i++)
		puts(st[i].str);

	free(st);
}

int compare(string* n1, string* n2) //오름차순 정렬. 내림차순은 1과 -1을 바꾸면 됨
{
	if (n1->len > n2->len) //1: 바꿈, -1: 안바꿈
		return 1;
	else if (n1->len < n2->len)
		return -1;
	else 
	{
		int s1 = 0, s2 = 0;
		for (int i = 0; i < n1->len; i++)
		{
			if (isdigit(n1->str[i]))
				s1 += (n1->str[i] - '0');
		}
		for (int i = 0; i < n2->len; i++)
		{
			if (isdigit(n2->str[i]))
				s2 += (n2->str[i] - '0');
		}
		if (s1 > s2)
			return 1;
		else if (s1 < s2)
			return -1;
		else
			return strcmp(n1->str, n2->str);
	}
}