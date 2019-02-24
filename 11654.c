#define _CRT_SECURE_NO_WARNINGS	

#include <stdio.h>
#include <Windows.h>

int main() {
	char l[2];
	l[1] = '\0';
	scanf("%c", l);
	printf("%d", l[0]);
	Sleep(1000);
	return 0;
}

//¸ÂÀ½