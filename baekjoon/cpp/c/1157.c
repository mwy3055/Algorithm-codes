#include <stdio.h>
#include <ctype.h>

void main() {
	char str[1000001] = { 0 }, c;
	int max, i = 0, j = 0, rm = 0, count[26] = { 0 };
	while ((c = getchar()) != '\n' &&  c != '\r' && c != ' ' && c != EOF) str[i++] = c; //�Է¿� ������ �ִ� �ɷ�..
	i = 0;
	while (str[i]) {
			str[i] = toupper(str[i]); //�빮�ڷ� ��� ��ȯ
			count[str[i++] - 'A']++;
	}	
	max = count[0];
	for (i = 1; i <= 25; i++) {
		if (max < count[i]) {
			max = count[i];
			rm = i; //�ִ��� ���ĺ� ����
			j = 0;
		}
		else if (max == count[i]) j++; //�ߺ�üũ
	}
	if (j == 0) printf("%c", rm + 'A');
	else printf("?");
}