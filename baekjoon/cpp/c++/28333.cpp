#include <bits/stdc++.h>

int n, m;
std::vector<int> graph[1001], rgraph[1001];

int d[1001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        graph[i].clear();
        rgraph[i].clear();
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
}

void bfs()
{
    std::memset(d, 0x3f, sizeof(d));
    std::queue<int> q;

    d[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front();
            q.pop();
            if (cur == n)
                return;

            for (auto &adj : graph[cur])
            {
                if (d[cur] + 1 < d[adj])
                {
                    d[adj] = d[cur] + 1;
                    q.push(adj);
                }
            }
        }
    }
}

void solve()
{
    bfs();

    std::vector<bool> visit(n + 1, false);

    std::queue<int> q;
    q.push(n);
    visit[n] = true;

    int dist = d[n];
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto cur = q.front();
            q.pop();

            for (auto &adj : rgraph[cur])
            {
                if (d[adj] == dist - 1 && !visit[adj])
                {
                    q.push(adj);
                    visit[adj] = true;
                }
            }
        }
        dist--;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i])
            std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        getinput();
        solve();
    }
}