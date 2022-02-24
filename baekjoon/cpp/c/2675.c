#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

void man(int k);
void zero(char *p); //문자열을 전부 널문자로 바꿈(입력받은 문자열의 끝을 구분하기 위해)

int str[160][1000];

void main() {
	int t;
	scanf("%d", &t);
	for (int j = 0; j < t; j++)
		man(j);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 160; j++) {
			if (str[j][i] == 0)
				break;
			printf("%c", str[j][i]);
		}
		printf("\n");
	}
}

void man(int k) {
	int r;
	char s[20];
	zero(s);
	scanf("%d %s", &r, s);
	for (int i = 0; *(s + i) != 0; i++) {
		for(int l = 0; l < r; l++)
			str[r*i+l][k] = s[i];
	}
}


void zero(char* p) {
	for (int i = 0; i < 20; i++)
		*(p + i) = 0;
}

//man 함수에서 수와 문자열을 입력받아서, r번 반복한 결과를 배열(str[160][1000])에 저장.
//main 함수에서 결과를 출력한다.