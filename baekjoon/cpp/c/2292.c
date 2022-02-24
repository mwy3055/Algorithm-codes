#include <stdio.h>

void main() {
	int n, count = 1;
	scanf("%d", &n);
	if (n == 1) printf("1");
	else {
		while (n > 1) n -= count++ * 6; //n=1이면 끝나야 함
		printf("%d", count);
	}
	//몇 줄 밖에 있는지를 알면 된다.
}