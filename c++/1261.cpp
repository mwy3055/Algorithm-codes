#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> Pair;
typedef pair<int, Pair> PPair;
int n, m;
char map[100][100];
const int INF = 0x7fffffff;

inline bool isin(int i, int j)
{
	return (0 <= i && i < n) && (0 <= j && j < m);
}

int dijk()
{
	int** dist = new int*[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = new int[m];
		for (int j = 0; j < m; j++)
			dist[i][j] = INF;
	}
	dist[0][0] = 0;
	char src[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
	priority_queue<PPair, vector<PPair>, greater<PPair>> pq;

	pq.push({ 0,{0,0} });
	while (!pq.empty())
	{
		Pair temp = pq.top().second;
		int& y = temp.first, &x = temp.second;
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			int sy = y + src[i][0], sx = x + src[i][1];
			if (isin(sy, sx) && dist[y][x] + map[sy][sx] < dist[sy][sx])
			{
				dist[sy][sx] = dist[y][x] + map[sy][sx];
				pq.push({ dist[sy][sx], { sy,sx } });
			}
		}
	}


	int result = dist[n - 1][m - 1];
	for (int i = 0; i < n; i++)
		delete[] dist[i];
	delete[] dist;
	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			map[i][j] -= '0';
		}

	cout << dijk();

}