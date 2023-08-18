#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordinfo {
	int len;
	char str[51];
} word; //word는 이제 하나의 자료형이다.

int cmp(word*, word*);

int main()
{
	int n, i;
	scanf("%d", &n);
	getchar(); //버퍼 비움
	word* wd = (word*)malloc(n * sizeof(word));
	for (i = 0; i < n; i++)
	{
		gets(wd[i].str);
		wd[i].len = strlen(wd[i].str);
	}

	qsort(wd, n,sizeof(word), cmp); //버블정렬:시간초과..

	for (i = 0; i < n - 1; i++) //같은 단어 처리 문제
	{
		if (strcmp(wd[i].str, wd[i+1].str) != 0)
			puts(wd[i].str);
	}
	puts(wd[n-1].str);
	free(wd);
}

int cmp(word* a,word* b) { //return이 1이면 좌우를 바꾸고 -1이면 바꾸지 않음. 이건 오름차순
	if (a->len > b->len) 
		return 1;
	else if (a->len < b->len) 
		return -1;
	else 
		return strcmp(a->str, b->str); 
}
//strcmp:사전식으로 앞에 것이 크면 양수, 뒤에 것이 크면 음수, 같으면 0 return