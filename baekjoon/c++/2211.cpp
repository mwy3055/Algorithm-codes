#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <functional>
using namespace std;
const int INF = 0x7fffffff;
typedef pair<int, int> Pair;
typedef vector<Pair>::iterator p_iterator;
//#define DEBUG
int* dijk(int n, vector<vector<Pair>>& adj)
{
	int* dist = new int[n + 1];
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;

	priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
	pq.push({0,1});
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
			}
		}
	}

#ifdef DEBUG
	for (int i = 1; i <= n; i++)
		cout << dist[i] << '\n';
#endif

	return dist;
}

bool find(vector<Pair>& adj, p_iterator& it, int dest)
{
	for (it = adj.begin(); it != adj.end(); it++)
	{
		if ((*it).second == dest)
			return true;
	}
	return false;
}
void deleteEdge(int d, int n, int*& dist, vector<vector<Pair>>& adj)
{
	//d는 각 컴퓨터(도착점)
	queue<int> q;
	q.push(d);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (i == now) continue;
			p_iterator t;
			if (find(adj[i], t, now))
			{
				if (dist[now] == dist[i] + (*t).first)
					q.push(i);
				else
					adj[i].erase(t);
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

	int* dist = dijk(n, adjList);
	/*
	//delete Pair
	for (int i = 2; i <= n; i++)
		deleteEdge(i, n, dist, adjList);
	*/
	//count Pair survived, print them
	vector<Pair> left;
	for (int i = 1; i <= n; i++)
	{
		for (Pair t : adjList[i])
		{
			if (dist[t.second] == dist[i] + t.first)
				left.push_back(Pair(i, t.second));
			p_iterator temp;
			if (find(adjList[t.second], temp, i))
				adjList[t.second].erase(temp);
		}
	}

	cout << left.size() << '\n';
	for (Pair i : left)
		cout << i.first << " " << i.second << '\n';




	delete[] dist;
}