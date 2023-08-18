#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct area
{
	int x, y, r;
	bool visit;
} area;

inline int sq(int i)
{
	return i * i;
}
inline bool adj(area& i, area& j)
{
	return (sq(i.r + j.r)) >= (sq(i.x - j.x) + sq(i.y - j.y));
}
void solve();
void bfs(area*, int, vector<vector<int>>&);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}

void solve()
{
	int n, cnt = 0;
	cin >> n;
	area* a = new area[n];
	vector<vector<int>> adjList(n);

	for (int i = 0; i < n; i++)
	{
		int x, y, r;
		cin >> x >> y >> r;
		a[i] = { x,y,r,false };
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (adj(a[i], a[j]))
				adjList[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!a[i].visit)
		{
			bfs(a, i, adjList);
			cnt++;
		}
	}

	cout << cnt << '\n';
	delete[] a;
}

void bfs(area* a, int i, vector<vector<int>>& adj)
{
	queue<int> q;

	a[i].visit = true;
	q.push(i);
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		for (int s : adj[t])
		{
			if (!a[s].visit)
			{
				a[s].visit = true;
				q.push(s);
			}
		}
	}
}