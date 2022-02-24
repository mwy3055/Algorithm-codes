#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int t, butt[3] = { 0 }; //A B C
	scanf("%d", &t);
	if (t % 10 != 0) //ºÒ°¡´É
	{
		printf("-1");
		return 0;
	}
	while (t >= 300)
	{
		butt[0]++;
		t -= 300;
	}
	while (t >= 60)
	{
		butt[1]++;
		t -= 60;
	}
	while (t >= 10)
	{
		butt[2]++;
		t -= 10;
	}
	if (t == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%d", butt[i]);
			if (i < 2) printf(" ");
		}
	}
	else
		printf("-1");

}
