#include <bits/stdc++.h>

std::vector<int> graph[401];
int flow[401][401], cap[401][401];

int solve(int &n, int start, int end)
{
    int ans = 0;
    std::vector<int> d(n + 1);
    while (true)
    {
        std::fill(d.begin(), d.end(), -1);
        std::queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto &adj : graph[top])
            {
                if (cap[top][adj] - flow[top][adj] > 0 && d[adj] == -1)
                {
                    q.push(adj);
                    d[adj] = top;
                    if (adj == end)
                        break;
                }
            }
        }
        if (d[end] == -1)
            break;
        int cur = end, f = 0x3f3f3f3f;
        while (cur != start)
        {
            auto before = d[cur];
            f = std::min(f, cap[before][cur] - flow[before][cur]);
            cur = before;
        }
        cur = end;
        while (cur != start)
        {
            auto before = d[cur];
            flow[before][cur] += f;
            flow[cur][before] -= f;
            cur = before;
        }
        ans += f;
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, p;
    std::cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int s, e;
        std::cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
        cap[s][e]++;
    }

    std::cout << solve(n, 1, 2) << '\n';
}