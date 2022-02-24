#include <bits/stdc++.h>
using namespace std;

using ADJ = map<int, int>;
using ADJLIST = vector<ADJ>;

void connect(ADJ &adj, int &b, int &c)
{
    if (adj.find(b) != adj.end())
        adj[b] = max(adj[b], c);
    else
        adj.insert(make_pair(b, c));
}
bool candrive(ADJLIST &adj, int &n, int &f1, int &f2, int &weight)
{
    queue<int> q;
    bool visit[n + 1] = {false};

    q.push(f1);
    visit[f1] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (top == f2)
            return true;

        for (auto &p : adj[top])
        {
            const auto &dest = p.first, &limit = p.second;
            if (!visit[dest] && weight <= limit)
            {
                q.push(dest);
                visit[dest] = true;
            }
        }
    }
    return false;
}
int my_parametric_search(ADJLIST &adj, int &n, int &f1, int &f2, int &maxc)
{
    int left = 0, right = maxc + 1, mid;
    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (candrive(adj, n, f1, f2, mid))
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ADJLIST adj(n + 1);

    int maxw = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        maxw = max(maxw, c);
        connect(adj[a], b, c);
        connect(adj[b], a, c);
    }

    int fac1, fac2;
    cin >> fac1 >> fac2;
    cout << my_parametric_search(adj, n, fac1, fac2, maxw);
}