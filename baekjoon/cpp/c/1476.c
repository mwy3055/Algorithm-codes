#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>

int main() {
	int x = 1, E, S, M, e = 1, s = 1, m = 1;
	scanf("%d %d %d", &E, &S, &M);
	while (1) {
		if ((E == e) && (S == s) && (M == m)) break;
		e++;
		s++;
		m++;
		x++;
		if ((E == e) && (S == s) && (M == m)) break;
		if (e == 15) e = 0;
		if (s == 28) s = 0;
		if (m == 19) m = 0;
	}
	printf("%d", x);
	return 0;
}

//중국인의 나머지 정리를 적용해보자.