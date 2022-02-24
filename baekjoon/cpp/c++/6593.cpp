#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> coord;
typedef pair<int, coord> Pair;
const int INF = 0x7ffffffe;

int l, r, c;

inline bool isin(int i, int j, int k)
{
	return (0 <= i && i < l) && (0 <= j && j < r) && (0 <= k && k < c);
}

string dijk(coord start, coord end, char*** map)
{
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	int*** dist = new int**[l];
	for (int i = 0; i < l; i++)
	{
		dist[i] = new int*[r];
		for (int j = 0; j < r; j++)
		{
			dist[i][j] = new int[c];
			for (int k = 0; k < c; k++)
				dist[i][j][k] = INF;
		}
	}
	dist[start.first][start.second.first][start.second.second] = 0;

	int src[6][3] = { {1,0,0},{-1,0,0},{0,1,0},{0,0,1},{0,-1,0},{0,0,-1} };
	pq.push({ 0, start });
	while (!pq.empty())
	{
		Pair s = pq.top();
		coord temp = pq.top().second;
		int z = temp.first, y = temp.second.first, x = temp.second.second;
		pq.pop();
		for (int i = 0; i < 6; i++)
		{
			int sz = z + src[i][0], sy = y + src[i][1], sx = x + src[i][2];
			if ((isin(sz, sy, sx) && map[sz][sy][sx] != '#') && (dist[z][y][x] + 1 < dist[sz][sy][sx]))
			{
				dist[sz][sy][sx] = dist[z][y][x] + 1;
				pq.push({ dist[sz][sy][sx],{sz,{sy,sx}} });
			}
		}
	}

	int ez = end.first, ey = end.second.first, ex = end.second.second;
	int rtn = dist[ez][ey][ex];
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < r; j++)
			delete[] dist[i][j];
		delete[] dist[i];
	}
	delete[] dist;
	if (rtn == INF)
		return "Trapped!";
	else
		return "Escaped in " + to_string(rtn) + " minute(s).";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		cin >> l >> r >> c;
		if (l == 0) return 0;

		coord start, end;
		char*** map = new char**[l];
		for (int i = 0; i < l; i++)
		{
			map[i] = new char*[r];
			for (int j = 0; j < r; j++)
			{
				map[i][j] = new char[c];
				for (int k = 0; k < c; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
						start = coord{ i,{j,k} };
					else if (map[i][j][k] == 'E')
						end = coord{ i,{j,k} };
				}
			}
		}

		cout << dijk(start, end, map) << '\n';
	}
}