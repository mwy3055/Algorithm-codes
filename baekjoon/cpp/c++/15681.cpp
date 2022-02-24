#include <bits/stdc++.h>
using namespace std;

int n, r, query[100001];
vector<int> adj[100001];
bool visit[100001];

int maketree(int node)
{
    int &rtn = query[node];
    rtn = 1;
    visit[node] = true;
    for (auto &adjnode : adj[node])
    {
        if (!visit[adjnode])
        {
            rtn += maketree(adjnode);
        }
    }
    return rtn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    maketree(r);
    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        cout << query[u] << '\n';
    }
}