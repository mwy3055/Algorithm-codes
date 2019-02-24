#include <stdio.h>

void even(int n,int line);
void odd(int n,int line);

void main() {
	int n, line = 1;
	scanf("%d", &n);
	if (n == 1) printf("1/1");
	else {
		while (n > line) n -= line++;
		if (line % 2) odd(n , line); //n�� �� �ٿ��� �� ��° ������ �˷���
		else even(n , line);
	}
}


void even(int n,int line) {
	int ja = 1, mo = line; //ù��°
	while (--n) {
		ja++;
		mo--;
	}
	printf("%d/%d", ja, mo);
}

void odd(int n,int line) {
	int ja = line, mo = 1; //ù��°
	while (--n) {
		mo++;
		ja--;
	}
	printf("%d/%d", ja, mo);
}