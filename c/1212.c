#include <stdio.h>
#include <math.h>

int main()
{
	char inp, cnt, swc = 1;
	while ((inp = getchar()) != EOF)
	{
		cnt = 1;
		if (inp == '\n')
			return 0;
		else if (inp == '0' && swc == 1)
		{
			printf("0");
			return 0;
		}
		inp -= '0';
		do
		{
			int dv = (int)pow(2, 3 - cnt);
			if (inp < dv && swc)
				continue;
			else if (inp < dv && swc == 0)
				printf("0");
			else
			{
				swc = 0;
				printf("1");
				inp -= dv;
			}
		} while (cnt++ != 3);
	}
}