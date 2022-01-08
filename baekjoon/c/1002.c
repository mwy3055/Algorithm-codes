#include <stdio.h>

int sq(int a)
{
	return a * a;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int x1, y1, r1, x2, y2, r2, ans;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int d = sq(x1 - x2) + sq(y1 - y2);

		if (x1 == x2 && y1 == y2 && r1 == r2)
			ans = -1;
		else if (d == sq(r1 - r2) || d == sq(r1 + r2))
			ans = 1;
		else if (d < sq(r1 - r2))
			ans = 0;
		else if (sq(r1 - r2) < d && d < sq(r1 + r2))
			ans = 2;
		else
			ans = 0;

		printf("%d\n", ans);
	}
}