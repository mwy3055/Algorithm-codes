#define _CRT_SECURE_NO_WARNINGS
//´ë¹®ÀÚ 65~90

#include <stdio.h>

void main() {
	char str[100];
	gets(str);
	for (int i = 0; str[i] != 0; i++) {
		if ((str[i] >= 65) && (str[i] <= 90))
			printf("%c", str[i]);
	}
	printf("\n");
}
