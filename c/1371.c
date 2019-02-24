#include <stdio.h>

int isLower(char c)
{
	return ('a' <= c) && (c <= 'z');
}

int main()
{
	int arr[26] = { 0 };
	char c;
	while ((c = getchar()) != EOF) {
		if (isLower(c))
			arr[c - 'a']++;
	}

	int tmax = arr[0];
	for (int i = 1; i < 26; i++)
	{
		if (tmax < arr[i])
			tmax = arr[i];
	}
	for (int i = 0; i < 26; i++)
		if (arr[i] == tmax)
			printf("%c", 'a' + i);

}