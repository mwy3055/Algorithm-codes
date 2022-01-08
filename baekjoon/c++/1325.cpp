#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define DEBUG
//사이클 어쩔?

int bfs(int& i, int& n, vector<vector<int>>& adj)
{
	bool* visit = new bool[n + 1];
	fill(visit + 1, visit + n + 1, false);
	int* q = new int[n + 1];

	int ans = 1, sidx = 0, siz = 1;
	q[0] = i;
	visit[i] = true;
	while (sidx < siz)
	{
		int top = q[sidx];
		for (int t : adj[top])
		{
			if (!visit[t])
			{
				visit[t] = true;
				q[siz++] = t;
				ans++;
			}
		}

		sidx++;
	}







	delete[] q;
	delete[] visit;
	return ans;
}

int dfs(int& i, int& n, bool* visit, vector<vector<int>>& adj)
{
	int ans = 1;
	visit[i] = true;

	for (int t : adj[i])
	{
		if (visit[t])
			continue;
		else
			ans += dfs(t, n, visit, adj);
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	int* chain = new int[n + 1];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[b].push_back(a);
	}

	int max_value = 1;
	vector<int> ans;
	for (int i = 1; i <= n; i++)
	{
		bool* visit = new bool[n + 1];
		fill(visit + 1, visit + n + 1, false);

//		chain[i] = dfs(i, n, visit, adj);
		chain[i] = bfs(i, n, adj);
		if (max_value < chain[i])
		{
			max_value = chain[i];
			ans.clear();
			ans.push_back(i);
		}
		else if (max_value == chain[i])
			ans.push_back(i);

		delete[] visit;
	}
#ifdef DEBUG
	for (int i = 1; i <= n; i++)
		cout << chain[i] << " ";
	cout << '\n';
#endif
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";

	delete[] chain;
}