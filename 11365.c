#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <string.h>

char str[100][1000];

void zero(char* p);
int get(); //END 입력받을 때까지 입력받음
void rvs(int n); //거꾸로 출력

void main() {
	zero(*str);
	int a=get(); 
	rvs(a);
}

int get() {
	int i = 0;
	char end[] = "END";
	gets(str[0]); //str[0][0]은 문자 한 글자를 의미.. 문장을 입력받는 상황이므로 행 변수까지만 쓴다.
	while (strcmp(end, str[i])) { //한 줄씩 입력받는 상황이므로 i행 대입
		i++;
		gets(str[i]);
	}
	return i-1; //str[0][i]=="END"
}

void rvs(int n) {
	for (int i = 0; i <= n; i++) {
		int lng = strlen(str[i]);
		for (int j = 0; j<lng; j++) {
			printf("%c", str[i][lng-j-1]); //문자열 길이가 lng일때 배열은 [0]~[lng-1]이다.
			if (lng-1 == j){
				printf("\n");
				break;
		}
		}
	}
}

 /*strcmp(const char *p1,const char *p2) : p1과 p2의 문자열을 아스키 코드를 통해 비교. 
   같으면 0, 첫번째가 두번째보다 빠르면 -1, 반대면 1 리턴*/

void zero(char* p) {
	for (int i = 0; i < 10000; i++)
		*(p + i) = 0;
}

