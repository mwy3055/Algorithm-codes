#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void over100(int p); //입력이 세 자리 수일 때에만

void main() {
	int num,i = 0, hns = 0;
	scanf("%d", &num);
	if (num < 100) printf("%d", num);
	else if (num == 100) printf("99");
	else if (num == 1000) printf("144");
	else over100(num);
}

void over100(int p) {
	int num = 0, t = 101;
	while (t <= p) {
		int t_h = t / 100, t_t = (t % 100) / 10, t_m = t % 10; //각각 백,십,일의 자리
		if (2 * t_t == t_h + t_m)
			num++;
		t++;
	}
	printf("%d", num + 99);
}