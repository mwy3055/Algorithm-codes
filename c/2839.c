#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int n, count = 0;
	scanf("%d", &n);
	if (n % 5 == 0) {
		count = n / 5;
		n = 0;
	}
	else if ((n % 3 == 0) && (n < 15)) { //15�� �� �� ���� ���
		count = n / 3;
		n = 0;
	}
	else //15�� �� �� ���� ���
		while (n > 5) { //n=5�� �� �� ����. n>=5���� ����� ����.
			if ((n % 3 == 0) && (n < 15)) break; //3,6,9,12:5�� ���� �ȵȴ�
			n -= 5;
			count++;
			if ((n % 3 == 0) && (n >= 15)) { //15�� ���� ������ ���� ����
				n -= 15;
				count += 3;
			}
		}
	if ((n % 3 == 0) && (n != 0)) { //������ break�� �������� ���
		count += n / 3;
		n = 0;
	}
	if (n == 0) printf("%d", count); //��Ȯ�ϰ� ������ �� ���� ��� 
	else printf("-1"); //�� �� ���
	return 0;
}