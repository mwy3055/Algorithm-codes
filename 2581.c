#include <stdio.h>
#include <math.h>

int pmcheck(int,int*);

int main()
{
	int n1, n2, sum = 0, min = 0;
	scanf("%d %d", &n1, &n2);
	for (int i = n1; i <= n2; i++)
		sum += pmcheck(i,&min);
	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);
}

int pmcheck(int n,int* min)
{
	if (n == 1)
		return 0;
	else
	{
		for (int i = 2; i <= (int)sqrt(n); i++)
		{
			if (n%i == 0)
				return 0;
		}
	}
	if (*min == 0) *min = n;
	return n;
}