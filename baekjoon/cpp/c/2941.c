#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void main() {
	char str[100];	
	gets_s(str, sizeof(str));
	int siz = strlen(str), i = 0;
	while (i < strlen(str)) { //어떻게 뺄까? 더 나은 방법을..
		if (str[i] == 'c' && (str[i + 1] == '=' || str[i + 1] == '-')) siz--;
		else if (str[i] == 'd' && ((str[i + 1] == 'z'&&str[i + 2] == '=') || str[i + 1] == '-')) siz--;
		else if ((str[i] == 'l' || str[i] == 'n') && str[i + 1] == 'j') siz--;
		else if ((str[i] == 's' || str[i] == 'z') && str[i + 1] == '=') siz--;
		i++;
	}
	printf("%d", siz);
}