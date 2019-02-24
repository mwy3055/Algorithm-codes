#include <stdio.h>

int counttime(char* str);

void main() {
	char str[16];
	gets(str);
	printf("%d", counttime(str));
}

int counttime(char* str) {
	int count = 0, i = 0;
	while (str[i]) 
	{
		int temp = str[i++] - 'A';
		if (temp <= 14)
		{
			count += temp / 3 + 3;
		}
		else
		{
			if (temp <= 18) count += 8;
			else if (temp >= 22) count += 10;
			else count += 9;
		}
	}
	return count;
}