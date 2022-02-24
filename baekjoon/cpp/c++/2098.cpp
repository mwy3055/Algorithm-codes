#include <iostream>
using namespace std;
const int MAX_VAL = 50000000;
int n;
int dp[16][65536], d[16][16];
inline int min(int a, int b)
{
	return a < b ? a : b;
}
int dfs(int i, int mask)
{
	if (mask == (1 << n) - 1)
		return d[i][0];

	int& cur = dp[i][mask];
	if (cur) return cur;
	cur = MAX_VAL;
	for (int j = 0; j < n; j++)
	{
		if (((mask&(1 << j)) == 0) && d[i][j] != 0)
		{
			int plus = dfs(j, mask | 1 << j);
			if (plus != 0)
				cur = min(cur, plus + d[i][j]);
		}
	}
	return cur;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> d[i][j];

	cout << dfs(0, 1);
}