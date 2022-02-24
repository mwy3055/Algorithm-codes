#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const int INF = 0x7fffffff;
typedef pair<int, int> Pair;
typedef vector<Pair>::iterator p_iterator;//#define DEBUG
void dijk(int n, int* dist, int* track, vector<vector<Pair>>& adj)
{
	fill(dist + 1, dist + n + 1, INF);
	fill(track + 1, track + n + 1, 0);
	dist[1] = 0;

	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
	pq.push({ 0,1 });
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (auto i : adj[u])
		{
			int cost = i.first, v = i.second;
			int& old = dist[v], renew = dist[u] + cost;
			if (renew < old)
			{
				old = renew;
				pq.push(Pair(renew, v));
				track[v] = u;
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
	vector<vector<Pair>> adjList;
	for (int i = 0; i <= n; i++)
		adjList.push_back(vector<Pair>());
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adjList[a].push_back(Pair(c, b));
		adjList[b].push_back(Pair(c, a));
	}

	int* dist = new int[n + 1], *track = new int[n + 1]; //거리, 역추적 배열
	dijk(n, dist, track, adjList);
	vector<Pair> left;
	for (int i = 2; i <= n; i++)
	{
		if (track[i] != 0)
			left.push_back(Pair(i, track[i]));
	}

	cout << left.size() << '\n';
	for (Pair i : left)
		cout << i.first << " " << i.second << '\n';

	delete[] dist;
	delete[] track;
}