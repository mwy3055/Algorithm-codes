#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> coord;

bool map[100][100], visit[100][100];
int n, m;

inline bool isin(int i, int j)
{
	return 0 <= i && i < m && 0 <= j && j < n;
}
int bfs(int i, int j)
{
	queue<coord> q;
	int src[4][2] = { {0,1},{0,-1},{1,0},{-1,0} }, area = 1;

	visit[i][j] = true;
	q.push(coord(i, j));
	while (!q.empty())
	{
		coord& top = q.front();
		int &ty = top.first, &tx = top.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int sy = ty + src[i][0], sx = tx + src[i][1];
			if (isin(sy, sx) && !map[sy][sx] && !visit[sy][sx])
			{
				visit[sy][sx] = true;
				q.push(coord(sy, sx));
				area++;
			}
		}
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> m >> n >> k;
	for (int a = 0; a < k; a++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++)
			for (int j = x1; j < x2; j++)
				map[i][j] = true;
	}

	vector<int> v;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[i][j] && !visit[i][j])
				v.push_back(bfs(i, j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i : v)
		cout << i << " ";
}