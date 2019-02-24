#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int> Pair; //거리, 정점
const int INF = 0x70000000;
inline int max(int a, int b) { return a > b ? a : b; }
void dijk(int& c, int& n, int* d, vector<vector<Pair>>& adj)
{
	priority_queue<Pair, vector<Pair>, greater<Pair>> q;

	d[c] = 0;
	q.push(Pair(0, c));
	while (!q.empty())
	{
		int top = q.top().second;
		q.pop();
		for (Pair i : adj[top])
		{
			int sidx = i.second;
			int& old = d[sidx], renew = d[top] + i.first;
			if (renew < old)
			{
				old = renew;
				q.push(Pair(renew, sidx));
			}
		}
	}
}

void solve()
{
	int n, d, c;
	cin >> n >> d >> c;
	vector<vector<Pair>> adj(n + 1);
	int* dist = new int[n + 1];
	fill(dist + 1, dist + n + 1, INF);
	for (int i = 0; i < d; i++)
	{
		int a, b, s;
		cin >> a >> b >> s;
		adj[b].push_back(Pair(s, a));
	}

	dijk(c, n, dist, adj);
	int max_dist = 0, cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != INF)
		{
			max_dist = max(max_dist, dist[i]);
			cnt++;
		}
	}
	cout << cnt << " " << max_dist << '\n';


	delete[] dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();
}