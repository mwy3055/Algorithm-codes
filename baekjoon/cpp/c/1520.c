#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arr[501][501];
int ans[501][501]; //여기에서 갈 수 있는 경우의 수

#define val(x,y) arr[y][x]

int dp(int m, int n, int x, int y)
{
	if (x == n && y == m)
		return 1;
	else if (ans[y][x] != -1) //방문한 지점일 때 값 리턴
		return ans[y][x];

	int temp = 0;
	if (x >= 2 && val(x, y) > val(x - 1, y))
		temp += dp(m, n, x - 1, y);
	if (x <= n - 1 && val(x, y) > val(x + 1, y))
		temp += dp(m, n, x + 1, y);
	if (y >= 2 && val(x, y) > val(x, y - 1))
		temp += dp(m, n, x, y - 1);
	if (y <= m - 1 && val(x, y) > val(x, y + 1))
		temp += dp(m, n, x, y + 1);

	return ans[y][x] = temp;
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
			ans[i][j] = -1; //(방문했지만 값이 0) <-> (아직 방문하지 않아서 값이 0)를 구분할 수 없어서 매번 문제를 푼다.
		}
	printf("%d", dp(m, n, 1, 1));
}