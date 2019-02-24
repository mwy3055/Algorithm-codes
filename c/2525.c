#include <stdio.h>

int main()
{
	int h, m, time;
	scanf_s("%d %d %d", &h, &m, &time);
	m += time;
	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	if (h >= 24)
		h -= 24;
	printf("%d %d", h, m);
}