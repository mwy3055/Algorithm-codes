#include <stdio.h>
#include <ctype.h>

void main() {
	char str[1000001] = { 0 }, c;
	int max, i = 0, j = 0, rm = 0, count[26] = { 0 };
	while ((c = getchar()) != '\n' &&  c != '\r' && c != ' ' && c != EOF) str[i++] = c; //입력에 문제가 있는 걸로..
	i = 0;
	while (str[i]) {
			str[i] = toupper(str[i]); //대문자로 모두 변환
			count[str[i++] - 'A']++;
	}	
	max = count[0];
	for (i = 1; i <= 25; i++) {
		if (max < count[i]) {
			max = count[i];
			rm = i; //최대의 알파벳 저장
			j = 0;
		}
		else if (max == count[i]) j++; //중복체크
	}
	if (j == 0) printf("%c", rm + 'A');
	else printf("?");
}