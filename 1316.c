#include <stdio.h>
#include <string.h>

int check(char* str, int* pc); //�׷� ����: ���� ���ڰ� �ڿ� ���� �� ������ �ȵȴ�

void main() {
	int n, i, count = 0;
	char str[100][101];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++) {
		gets(str[i]);
		count+=check(*(str + i), &count);
	}
	printf("%d", count);
}


int check(char* str, int* pc) 
{
	int apb[26] = { 0 }, i = 0;
	if (strlen(str) == 1) return 1;
	else 
	{
		while (str[i]) 
		{
			if (str[i] != str[i + 1])
			{
				apb[str[i] - 'a']++;
				if (apb[str[i + 1] - 'a'] != 0) return 0;
			}
			i++;
		}
		return 1;
	}
}