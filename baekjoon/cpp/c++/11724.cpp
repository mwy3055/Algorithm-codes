#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int& i, vector<vector<int>>& adj, vector<bool>& visit)
{
	queue<int> q;

	visit[i] = false;
	q.push(i);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		for (int t : adj[top])
		{
			if (visit[t] == false)
			{
				visit[t] = true;
				q.push(t);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<bool> visit(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			bfs(i, adj, visit);
			cnt++;
		}
	}
	cout << cnt;
}