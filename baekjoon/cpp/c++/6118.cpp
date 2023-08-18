#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> Pair; //거리, 정점
const int INF = 0x7f000000;

void dijk(int n, int* dist, vector<vector<int>> adj)
{
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push({ 0,1 });
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for (int i : adj[u])
		{
			int& old = dist[i], renew = dist[u] + 1;
			if (renew < old)
			{
				old = renew;
				pq.push({ renew,i });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> adjList;
	for (int i = 0; i <= n; i++)
		adjList.push_back(vector<int>());
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	int* dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	dijk(n, dist, adjList);

	int max_dist = dist[2], max_idx = 2, max_cnt = 1;
	for (int i = 3; i <= n; i++)
	{
		if (max_dist < dist[i])
		{
			max_dist = dist[i];
			max_idx = i;
			max_cnt = 1;
		}
		else if (max_dist == dist[i])
			max_cnt++;
	}

	cout << max_idx << " " << max_dist << " " << max_cnt;

	delete[] dist;
}