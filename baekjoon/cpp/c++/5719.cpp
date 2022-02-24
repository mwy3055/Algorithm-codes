#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> Pair;		//거리, 목적지
typedef vector<Pair>::iterator p_iterator;
const int INF = 0x7f000000;

bool find(vector<Pair>& adj, p_iterator& it, int dest)
{
	for (it = adj.begin(); it != adj.end(); it++)
	{
		if ((*it).second == dest)
			return true;
	}
	return false;
}
void deleteEdge(vector<vector<Pair>>& adj, queue<int> q, int* dist, int n)
{
	while (!q.empty())
	{
		int search = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (i == search) continue;
			p_iterator t;
			//간선이 존재하고 그 간선이 최단거리의 일부이면
			if (find(adj[i], t, search) && (dist[search] == dist[i] + (*t).first))
			{
				adj[i].erase(t);
				q.push(i);
			}
		}
	}
}
void dijk(int n, int s, int d, vector<vector<Pair>>& adj, queue<int> q) 
{
	//최단경로 다익스트라->간선 삭제
	int* dist = new int[n];
	fill(dist, dist + n, INF);
	dist[s] = 0;
	
	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push({ 0,s });	
	while (!pq.empty())
	{
		Pair now = pq.top();
		int search = now.second;
		pq.pop();
		for (Pair t : adj[search])
		{
			int scost = t.first, sidx = t.second;
			int& old = dist[sidx], renew = dist[search] + scost;
			if (renew < old)
			{
				old = renew;
				pq.push({ renew, sidx });
			}
		}
	}

	q.push(d);
	deleteEdge(adj, q, dist, n);

	delete[] dist;
}

int dijk(int n, int s, int d, vector<vector<Pair>> adj)
{
	//거의 최단 경로 다익스트라
	int* dist = new int[n];
	fill(dist, dist + n, INF);
	dist[s] = 0;

	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push({ 0,s });
	while (!pq.empty())
	{
		Pair now = pq.top();
		int search = now.second;
		pq.pop();
		for (Pair t : adj[search])
		{
			int scost = t.first, sidx = t.second;
			int& old = dist[sidx], renew = dist[search] + t.first;
			if (renew < old)
			{
				old = renew;
				pq.push({ renew, sidx });
			}
		}
	}

	int rtn = dist[d];
	delete[] dist;
	return rtn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		int n, m, s, d;
		cin >> n >> m;
		if (n == 0) return 0;

		cin >> s >> d;

		vector<vector<Pair>> adjList;
		for (int i = 0; i < n; i++)
			adjList.push_back(vector<Pair>());
		for (int i = 0; i < m; i++)
		{
			int u, v, p;
			cin >> u >> v >> p;
			adjList[u].push_back({ p,v });
		}

		dijk(n, s, d, adjList, queue<int>());
		int almost = dijk(n, s, d, adjList);
		cout << ((almost == INF) ? -1 : almost) << '\n';
	}
}