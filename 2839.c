#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main() {
	int n, count = 0;
	scanf("%d", &n);
	if (n % 5 == 0) {
		count = n / 5;
		n = 0;
	}
	else if ((n % 3 == 0) && (n < 15)) { //15를 뺄 수 없을 경우
		count = n / 3;
		n = 0;
	}
	else //15로 뺄 수 있을 경우
		while (n > 5) { //n=5가 될 수 없음. n>=5여도 상관은 없다.
			if ((n % 3 == 0) && (n < 15)) break; //3,6,9,12:5를 빼면 안된다
			n -= 5;
			count++;
			if ((n % 3 == 0) && (n >= 15)) { //15로 빼도 문제가 되지 않음
				n -= 15;
				count += 3;
			}
		}
	if ((n % 3 == 0) && (n != 0)) { //위에서 break로 빠져나온 경우
		count += n / 3;
		n = 0;
	}
	if (n == 0) printf("%d", count); //정확하게 가져갈 수 있을 경우 
	else printf("-1"); //안 될 경우
	return 0;
}