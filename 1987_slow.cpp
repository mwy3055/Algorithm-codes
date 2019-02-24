#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

typedef struct coord {
	int y, x;
} coord;

char map[20][20];
int r, c, ans, src[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline bool isin(int i, int j)
{
	return 0 <= i && i < r && 0 <= j && j < c;
}
void dfs(int i, int j, int dep, vector<bool>& used)
{
	used[map[i][j] - 'A'] = true;
	ans = max(ans, dep);
	for (int k = 0; k < 4; k++)
	{
		int sy = i + src[k][0], sx = j + src[k][1];
		if (isin(sy, sx) && !used[map[sy][sx] - 'A'])
		{
			dfs(sy, sx, dep + 1, used);
		}
	}
	used[map[i][j] - 'A'] = false;
}

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", map[i]);

	vector<bool> used(26, false);
	dfs(0, 0, 0, used);

	printf("%d", ans);
}