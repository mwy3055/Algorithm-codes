#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<int, Pair> PPair;
const int INF = 0x7fffffff;

inline bool isin(int i, int j, int n)
{
	return (0 <= i && i < n) && (0 <= j && j < n);
}

int dijk(int n, char** map)
{
	int** dist = new int*[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = new int[n];
		for (int j = 0; j < n; j++)
			dist[i][j] = INF;
	}
	dist[0][0] = map[0][0];
	priority_queue<PPair, vector<PPair>, greater<PPair>> pq;
	int src[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

	pq.push({ dist[0][0], {0,0} });
	while (!pq.empty())
	{
		Pair temp = pq.top().second;
		pq.pop();
		int& y = temp.first, &x = temp.second;
		for (int i = 0; i < 4; i++)
		{
			int sy = y + src[i][0], sx = x + src[i][1];
			if (isin(sy, sx, n) && dist[y][x] + map[sy][sx] < dist[sy][sx])
			{
				dist[sy][sx] = dist[y][x] + map[sy][sx];
				pq.push({ dist[sy][sx],{sy,sx} });
			}
		}
	}

	int rtn = dist[n - 1][n - 1];
	for (int i = 0; i < n; i++)
		delete[] dist[i];
	delete[] dist;
	return rtn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;
	while (true)
	{
		int n;
		cin >> n;
		if (n == 0) return 0;

		/* make data */
		char** map = new char*[n];
		for (int i = 0; i < n; i++)
		{
			map[i] = new char[n];
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				map[i][j] -= '0';
			}
		}
		cout << "Problem " << cnt++ << ": " << dijk(n, map) << '\n';

		for (int i = 0; i < n; i++)
			delete[] map[i];
		delete[] map;
	}
}