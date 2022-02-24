#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct wordinfo {
	int len;
	char str[51];
} word; //word�� ���� �ϳ��� �ڷ����̴�.

int cmp(word*, word*);

int main()
{
	int n, i;
	scanf("%d", &n);
	getchar(); //���� ���
	word* wd = (word*)malloc(n * sizeof(word));
	for (i = 0; i < n; i++)
	{
		gets(wd[i].str);
		wd[i].len = strlen(wd[i].str);
	}

	qsort(wd, n,sizeof(word), cmp); //��������:�ð��ʰ�..

	for (i = 0; i < n - 1; i++) //���� �ܾ� ó�� ����
	{
		if (strcmp(wd[i].str, wd[i+1].str) != 0)
			puts(wd[i].str);
	}
	puts(wd[n-1].str);
	free(wd);
}

int cmp(word* a,word* b) { //return�� 1�̸� �¿츦 �ٲٰ� -1�̸� �ٲ��� ����. �̰� ��������
	if (a->len > b->len) 
		return 1;
	else if (a->len < b->len) 
		return -1;
	else 
		return strcmp(a->str, b->str); 
}
//strcmp:���������� �տ� ���� ũ�� ���, �ڿ� ���� ũ�� ����, ������ 0 return