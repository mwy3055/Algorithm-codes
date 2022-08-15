#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, m, x;
std::vector<int> graph[100001], graph_rev[100001]; // graph: 잘하는 -> 못하는, graph_rev: 못하는 -> 잘하는

void getinput()
{
    std::cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph_rev[b].push_back(a);
    }
}

int above(int x)
{
    int count = 0;
    std::queue<int> q;
    std::vector<bool> visit(n + 1, false);

    q.push(x);
    visit[x] = true;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        count++;
        for (auto &adj : graph_rev[top])
        {
            if (!visit[adj])
            {
                q.push(adj);
                visit[adj] = true;
            }
        }
    }
    return count - 1;
}

int below(int x)
{
    int count = 0;
    std::queue<int> q;
    std::vector<bool> visit(n + 1, false);

    q.push(x);
    visit[x] = true;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        count++;
        for (auto &adj : graph[top])
        {
            if (!visit[adj])
            {
                q.push(adj);
                visit[adj] = true;
            }
        }
    }
    return count - 1;
}

void solve()
{
    // 최고 순위 = (내 위에 있는 노드 수) + 1
    int max = above(x) + 1;

    // 최저 순위 = n - (내 아래에 있는 노드 수)
    int min = n - below(x);
    std::cout << max << ' ' << min << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}