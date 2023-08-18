#include <bits/stdc++.h>
using namespace std;

using Pair = pair<int, int>;

//������ ����(���⼭�� 1��)���� ���� �ָ� �ִ� ���� B�� ���Ѵ�.
//B�κ��� ���� �ָ� �ִ� ���������� �Ÿ��� Ʈ���� �����̴�.

int bfs(int &v, int start, vector<vector<Pair>> &adj, int &ans)
{
    bool visit[v + 1] = {false};
    int d[v + 1] = {0};
    queue<int> q;

    d[start] = 0;
    visit[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        for (auto &next : adj[top])
        {
            int &dst = next.first, &dist = next.second;
            if (visit[dst])
                continue;

            d[dst] = d[top] + dist;
            visit[dst] = true;
            q.push(dst);
        }
    }

    int maxi = 1;
    for (int i = 2; i <= v; i++)
    {
        if (d[maxi] < d[i])
            maxi = i;
    }
    ans = d[maxi];
    return maxi;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v;
    cin >> v;
    vector<vector<Pair>> adj(v + 1, vector<Pair>());

    for (int i = 1; i <= v; i++)
    {
        int nth;
        cin >> nth;
        while (true)
        {
            int a, b;
            cin >> a;
            if (a == -1)
                break;

            cin >> b;
            adj[a].push_back(Pair(nth, b));
            adj[nth].push_back(Pair(a, b));
        }
    }

    int ans;
    int maxidx = bfs(v, 1, adj, ans);
    bfs(v, maxidx, adj, ans);
    cout << ans;
}