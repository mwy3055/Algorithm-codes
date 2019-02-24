#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, a;
	int inclength = 1, declength = 1, tempinc = 1, tempdec = 1;
	scanf("%d %d", &n, &a);
	n--;
	while (n--)
	{
		int b;
		scanf("%d", &b);
		if (a == b)
		{
			tempinc++;
			tempdec++;
		}
		else if (a < b)
		{
			tempinc++;
			if (declength < tempdec)
				declength = tempdec;
			tempdec = 1;
		}
		else
		{
			tempdec++;
			if (inclength < tempinc)
				inclength = tempinc;
			tempinc = 1;
		}
		a = b;
	}
	if (declength < tempdec)
		declength = tempdec;
	if (inclength < tempinc)
		inclength = tempinc;
	printf("%d", inclength > declength ? inclength : declength);
}