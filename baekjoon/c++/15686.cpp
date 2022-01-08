#include <iostream>
using namespace std;

struct coord {
	int y, x;
};
const int INF = 0x7fffffff;

int n, m, sidx, hidx, ans = INF;
int dist[100];
coord store[13], house[100];
bool selected[13];

inline int distance(coord& s, coord& h)
{
	return abs(s.x - h.x) + abs(s.y - h.y);
}
inline int min(int a, int b)
{
	return a < b ? a : b;
}
inline void fill()
{
	for (int i = 0; i < hidx; i++)
		dist[i] = INF;

}
void solve()
{
	fill();
	for (int i = 0; i < sidx; i++)
	{
		if (selected[i])
		{
			for (int j = 0; j < hidx; j++)
			{
				dist[j] = min(dist[j], distance(store[i], house[j]));
			}
		}
	}

	int tmin = 0;
	for (int i = 0; i < hidx; i++)
	{
		tmin += dist[i];
	}
	if (tmin < 0) int a = 1;
	ans = min(ans, tmin);
}

void dfs(int dep, int icl)
{
	if (icl == m)
	{
		solve();
		return;
	}
	else if (sidx - dep < m - icl)
		return;

	selected[dep] = true;
	dfs(dep + 1, icl + 1);
	selected[dep] = false;
	dfs(dep + 1, icl);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int area;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> area;
			if (area == 1)
				house[hidx++] = { i,j };
			else if (area == 2)
				store[sidx++] = { i,j };
		}
	}

	dfs(0, 0);
	cout << ans;
}