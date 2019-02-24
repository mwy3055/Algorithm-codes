#include <stdio.h>

int main()
{
	int can = 0, want = 0, i = 0;
	char str[1001];
	gets(str);
	while (str[i])
	{
		if (str[i] == 'a')
			can++;
		i++;
	}
	gets(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'a')
			want++;
		i++;
	}
	if (can >= want)
		printf("go");
	else
		printf("no");
}