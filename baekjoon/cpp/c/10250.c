#include <stdio.h>

void calc();

void main() {
	int t;
	scanf("%d", &t);
	while (t--) calc();
}

void calc() {
	int h, w, n, floor;
	scanf("%d %d %d", &h, &w, &n);
	floor = n % h ? n % h : h; //�������� 0�϶��� �� ������ �ִ�.
	printf("%d%02d\n", floor, 1 + (n - 1) / h); //1~n���� roomno=1
}