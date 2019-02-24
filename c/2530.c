#include <stdio.h>

int main()
{
	int h, m, s, sec;
	scanf_s("%d %d %d %d", &h, &m, &s, &sec);
	s += sec;
	if (s >= 60)
	{
		m += s / 60;
		s %= 60;
	}
	if (m >= 60)
	{
		h += m / 60;
		m %= 60;
	}
	while (h >= 24)
		h -= 24;
	printf("%d %d %d", h, m, s);
}