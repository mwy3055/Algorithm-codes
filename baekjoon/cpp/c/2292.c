#include <stdio.h>

void main() {
	int n, count = 1;
	scanf("%d", &n);
	if (n == 1) printf("1");
	else {
		while (n > 1) n -= count++ * 6; //n=1�̸� ������ ��
		printf("%d", count);
	}
	//�� �� �ۿ� �ִ����� �˸� �ȴ�.
}