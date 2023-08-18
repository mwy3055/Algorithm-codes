#include <stdio.h>

void how(int n);

void main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	c *= a * b; //c=a*b*c
	how(c);
}
void how(int n) {
	int count[10] = { 0 } , i = 0;
	while (n != 0) {
		count[n % 10]++;
		n /= 10;
	}
	for (; i <= 9; i++)
		printf("%d\n", count[i]);
}