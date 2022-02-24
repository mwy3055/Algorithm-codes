#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pair; //거리, 목적지
const int INF = 0x7fffffff;

void dijk(int v, int k, int* dist, vector<Pair>* adjList)
{
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
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e, p1, p2;
	
	cin >> n >> e;
	vector<Pair>* adjList = new vector<Pair>[n + 1];
	int* dist = new int[n + 1];
	for (int i = 0; i < e; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		adjList[start].push_back({ dist,end });
		adjList[end].push_back({ dist,start });
	}
	cin >> p1 >> p2;

	long long r1, r2;
	dijk(n, n, dist, adjList);
	r1 = dist[p2];
	r2 = dist[p1];

	dijk(n, p2, dist, adjList);
	r1 += dist[p1];
	r2 += dist[1];

	dijk(n, p1, dist, adjList);
	r1 += dist[1];
	r2 += dist[p2];

	if (r1 >= INF && r2 >= INF)
		cout << -1;
	else
		cout << min(r1, r2);


	delete[] dist;
	delete[] adjList;
}