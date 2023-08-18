#include <stdio.h>

int main() {
	int num, t, o, temp, c = 0;
	scanf("%d", &num);
	t = num / 10;
	o = num % 10;
	do {
		temp = t + o;
		t = o;
		o = temp % 10;
		c++;
	} while (num!=t*10+o);
	printf("%d", c);
}