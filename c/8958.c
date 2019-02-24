#include <stdio.h>

void check();

void main() {
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) check();
}

void check() {
	char str[80];
	int i = 0, sum = 0, count = 1;
	gets_s(str,sizeof(str));
	while (str[i]) {
		switch (str[i++]) {
		case 'O':
			sum += count++;
			break;
		case 'X':
			count = 1;
			break;
		}
	}
	printf("%d\n", sum);
}