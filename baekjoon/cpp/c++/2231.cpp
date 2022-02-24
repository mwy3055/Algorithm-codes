#include <cstdio>
using namespace std;

int disjoint(int i)
{
	int sum = i;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		if (disjoint(i) == n)
			return !printf("%d", i);
	}
	printf("0");
}