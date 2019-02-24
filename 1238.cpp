#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pair; //거리, 목적지
const int INF = 0x7fffffff;

void dijk(int v, int k, vector<Pair>* adjList,int* dist)
{
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push({ 0,k });
	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		for (Pair i : adjList[u])
		{
			int& old = dist[i.second], renew = dist[u] + i.first;
			if (renew < old)
			{
				old = renew;
				pq.push({ renew,i.second });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	int* dist_go = new int[n + 1];
	int* dist_come = new int[n + 1];
	fill(dist_go, dist_go + n + 1, INF);
	fill(dist_come, dist_come + n + 1, INF);
	dist_go[x] = dist_come[x] = 0;

	vector<Pair>* go = new vector<Pair>[n + 1];
	vector<Pair>* come = new vector<Pair>[n + 1];
	for (int i = 0; i < m; i++)
	{
		int p1, p2, cost;
		cin >> p1 >> p2 >> cost;
		go[p1].push_back({ cost,p2 });
		come[p2].push_back({ cost,p1 });
	}

	dijk(n, x, go, dist_go);
	dijk(n, x, come, dist_come);

	int max_dist = 0;
	for (int i = 1; i <= n; i++)
		max_dist = max(max_dist, dist_go[i] + dist_come[i]);
	cout << max_dist;
}