#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> coord;
int n, m, emp;
char map[8][8];
inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline bool isin(int i, int j)
{
	return 0 <= i && i < n && 0 <= j && j < m;
}
int bfs(vector<coord>& v, coord& i, coord& j, coord& k)
{
	map[i.first][i.second] = '1';
	map[j.first][j.second] = '1';
	map[k.first][k.second] = '1';

	bool visit[8][8] = { false };
	queue<coord> q;
	for (coord t : v)
		q.push(t);
	
	int src[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, temp_ans = emp - 3;
	while (!q.empty())
	{
		coord& top = q.front();
		q.pop();
		int ty = top.first, tx = top.second;
		for (int i = 0; i < 4; i++)
		{
			int sy = ty + src[i][0], sx = tx + src[i][1];
			if (isin(sy, sx))
			{
				if (map[sy][sx] == '0' && !visit[sy][sx])
				{
					q.push(coord(sy, sx));
					visit[sy][sx] = true;
					temp_ans--;
				}
			}
		}
	}

	map[i.first][i.second] = '0';
	map[j.first][j.second] = '0';
	map[k.first][k.second] = '0';
	return temp_ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<coord> e, v;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '0')
			{
				emp++;
				e.push_back(coord(i, j));
			}
			else if (map[i][j] == '2')
				v.push_back(coord(i, j));
		}
	}

	int siz = e.size(), ans = 0;
	for (int i = 0; i < siz; i++)
	{
		for (int j = i + 1; j < siz; j++)
		{
			for (int k = j + 1; k < siz; k++)
			{
				ans = max(ans, bfs(v, e[i], e[j], e[k]));
			}
		}
	}
	cout << ans;
}