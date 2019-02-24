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

void self(int n,int* nat) { //계산 후 대입하는 함수
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

//셀프 넘버 판단: 생성자 1부터 10000까지 모두 확인 후, 아닌 수 출력 ->9972까지만 확인해도 충분함

/* self함수의 while문을 다음과 같이 바꿔도 작동한다.
int tt = n / 10000, th = n / 1000, hd = (n - th*1000) / 100, ten = n % 100 / 10, one = n % 10;
int calc= n + tt + th + hd + ten + one;

오류 원인: hd=(n-th)/100이라고 코딩함
*/
