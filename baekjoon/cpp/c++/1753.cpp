#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pair; //거리, 목적지
const int INF = 0x7fffffff;

void dijk(int v, int k, vector<Pair>* adjList)
{
	int* dist = new int[v + 1];
	fill(dist, dist + v + 1, INF);
	dist[k] = 0;
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

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << '\n';
	}
	delete[] dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e, k;
	cin >> v >> e >> k;
	vector<Pair>* adjList = new vector<Pair>[v + 1];
	for (int i = 0; i < e; i++)
	{
		int start, dest, cost;
		cin >> start >> dest >> cost;
		adjList[start].push_back({ cost,dest });
	}
	dijk(v, k, adjList);
	delete[] adjList;
}