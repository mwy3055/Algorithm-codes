#include <stdio.h>

void self(int n,int* nat);

int main() {
	int nat[10000] = { 0 }, i = 1;
	for (; i <= 9972; i++) {
		self(i, nat);
	}
	for (i = 0; i <= 9999; i++) {
		if (nat[i] == 0) printf("%d\n", i + 1);
	}
}

void self(int n,int* nat) { //��� �� �����ϴ� �Լ�
	int calc = n;
	while (n != 0) {
		calc += n % 10;
		n /= 10;
	}
	if (calc <= 10000) {
		nat[calc - 1] = calc;
		self(calc, nat);
	}
}

//���� �ѹ� �Ǵ�: ������ 1���� 10000���� ��� Ȯ�� ��, �ƴ� �� ��� ->9972������ Ȯ���ص� �����

/* self�Լ��� while���� ������ ���� �ٲ㵵 �۵��Ѵ�.
int tt = n / 10000, th = n / 1000, hd = (n - th*1000) / 100, ten = n % 100 / 10, one = n % 10;
int calc= n + tt + th + hd + ten + one;

���� ����: hd=(n-th)/100�̶�� �ڵ���
*/
