#include <bits/stdc++.h>

int v, e;
std::vector<int> graph[10001];

int order[10001], ord; // order found at DFS
bool visit[10001];
bool iscut[10001]; // whether i-th vertex is cut vertex

// returns earliest visitable node among its child
int dfs(int cur, bool isroot)
{
    order[cur] = ++ord;
    visit[cur] = true;

    int ret = order[cur]; // min(order of child, including cur)
    int child_cnt = 0;
    for (auto &e : graph[cur])
    {
        if (visit[e])
        {
            ret = std::min(ret, order[e]);
        }
        else
        {
            child_cnt++;
            auto low = dfs(e, false);
            if (!isroot && low >= order[cur])
                iscut[cur] = true;
            ret = std::min(ret, low);
        }
    }
    if (isroot)
        iscut[cur] = child_cnt >= 2;
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= v; i++)
    {
        std::sort(graph[i].begin(), graph[i].end());
        graph[i].erase(std::unique(graph[i].begin(), graph[i].end()), graph[i].end());
    }

    for (int i = 1; i <= v; i++)
    {
        if (!visit[i])
            dfs(i, true);
    }

    std::vector<int> ans;
    for (int i = 1; i <= v; i++)
    {
        if (iscut[i])
            ans.push_back(i);
    }
    std::cout << ans.size() << '\n';
    for (auto &a : ans)
        std::cout << a << ' ';
}