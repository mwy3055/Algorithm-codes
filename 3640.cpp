#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define CRT_SECURE_NO_WARNINGS
typedef pair<int, int> Pair;		//거리, 목적지
typedef vector<Pair>::iterator p_iterator;
const int INF = 0x70000000;

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
int dijk(int v, vector<vector<Pair>>& adj, queue<int> q)
{
	//최단경로 다익스트라->간선 삭제
	int* dist = new int[v + 1];
	fill(dist, dist + v + 1, INF);
	dist[1] = 0;

	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push(Pair(0, 1));
	while (!pq.empty())
	{
		int now = pq.top().second;
		pq.pop();
		for (Pair t : adj[now])
		{
			int scost = t.first, sidx = t.second;
			int& old = dist[sidx], renew = dist[now] + scost;
			if (renew < old)
			{
				old = renew;
				pq.push({ renew, sidx });
			}
		}
	}

	q.push(v);
	deleteEdge(adj, q, dist, v);

	int rtn = dist[v];
	delete[] dist;
	return rtn;
}

int dijk(int v, vector<vector<Pair>>& adj)
{
	int* dist = new int[v + 1];
	fill(dist, dist + v + 1, INF);
	dist[1] = 0;

	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

	pq.push(Pair(0, 1));
	while (!pq.empty())
	{
		int now = pq.top().second;
		pq.pop();
		for (Pair t : adj[now])
		{
			int scost = t.first, sidx = t.second;
			int &old = dist[sidx], renew = dist[now] + scost;
			if (renew < old)
			{
				old = renew;
				pq.push(Pair(renew, sidx));
			}
		}
	}

	int rtn = dist[v];
	delete[] dist;
	return rtn;
}
int main()
{
	int v, e;
	while (scanf("%d %d", &v, &e) == 2)
	{
		vector<vector<Pair>> adj(v + 1);
		for (int i = 0; i < e; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back(Pair(c, b));
		}
		cout << dijk(v, adj, queue<int>()) + dijk(v, adj) << '\n';
	}
}