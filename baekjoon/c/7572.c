#include <stdio.h>

int main()
{
	char ji, gan;
	int n;
	scanf_s("%d", &n);
	gan = ((n - 2) % 10 + 8) % 10; //   (((n-1)-1)%10+1)+6
	ji = (n - 2) % 12 + 1 + 'J'; //   (((n-1)-1)%12+1)+'J'
	if (ji > 'L')
		ji -= 12;
	printf("%c%d", ji, gan);
}