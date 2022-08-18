#include <bits/stdc++.h>

int n, m;
std::vector<int> graph[501];
bool visit[501];

void init()
{
    for (int i = 1; i <= 500; i++)
        graph[i].clear();
    std::memset(visit, false, sizeof(visit));
}

void getinput()
{
    std::cin >> n >> m;
    if (n == 0 && m == 0)
        exit(0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

bool bfs(int root)
{
    std::queue<int> q;
    std::vector<int> nodes;

    q.push(root);
    visit[root] = true;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        nodes.push_back(top);
        for (auto &adj : graph[top])
        {
            if (!visit[adj])
            {
                q.push(adj);
                visit[adj] = true;
            }
        }
    }

    int node_count = nodes.size(), edge_count = 0;
    for (auto &node : nodes)
        edge_count += graph[node].size();
    return (edge_count / 2) == (node_count - 1);
}

int solve()
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i] && bfs(i))
            count++;
    }
    return count;
}

void print(int t, int ans)
{
    std::cout << "Case " << t << ": ";
    if (ans == 0)
        std::cout << "No trees." << '\n';
    else if (ans == 1)
        std::cout << "There is one tree." << '\n';
    else
        std::cout << "A forest of " << ans << " trees." << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t = 1;
    while (true)
    {
        init();
        getinput();
        int ans = solve();
        print(t, ans);
        t++;
    }
}