#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <string.h>

char str[100][1000];

void zero(char* p);
int get(); //END �Է¹��� ������ �Է¹���
void rvs(int n); //�Ųٷ� ���

void main() {
	zero(*str);
	int a=get(); 
	rvs(a);
}

int get() {
	int i = 0;
	char end[] = "END";
	gets(str[0]); //str[0][0]�� ���� �� ���ڸ� �ǹ�.. ������ �Է¹޴� ��Ȳ�̹Ƿ� �� ���������� ����.
	while (strcmp(end, str[i])) { //�� �پ� �Է¹޴� ��Ȳ�̹Ƿ� i�� ����
		i++;
		gets(str[i]);
	}
	return i-1; //str[0][i]=="END"
}

void rvs(int n) {
	for (int i = 0; i <= n; i++) {
		int lng = strlen(str[i]);
		for (int j = 0; j<lng; j++) {
			printf("%c", str[i][lng-j-1]); //���ڿ� ���̰� lng�϶� �迭�� [0]~[lng-1]�̴�.
			if (lng-1 == j){
				printf("\n");
				break;
		}
		}
	}
}

 /*strcmp(const char *p1,const char *p2) : p1�� p2�� ���ڿ��� �ƽ�Ű �ڵ带 ���� ��. 
   ������ 0, ù��°�� �ι�°���� ������ -1, �ݴ�� 1 ����*/

void zero(char* p) {
	for (int i = 0; i < 10000; i++)
		*(p + i) = 0;
}

