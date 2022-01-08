#include <bits/stdc++.h>

std::vector<int> graph[2002];
int cap[2002][2002], flow[2002][2002];

int solve(int start, int end, int limit)
{
    std::vector<int> track(end - start + 1);
    int rtn = 0;
    while (rtn < limit)
    {
        std::fill(track.begin(), track.end(), -1);
        std::queue<int> q;
        q.push(start);
        track[start] = start;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto &adj : graph[top])
            {
                if (cap[top][adj] - flow[top][adj] > 0 && track[adj] == -1)
                {
                    q.push(adj);
                    track[adj] = top;
                    if (adj == end)
                        break;
                }
            }
        }
        if (track[end] == -1)
            break;
        int maxflow = 0x3f3f3f3f, cur = end;
        while (cur != start)
        {
            auto &bef = track[cur];
            maxflow = std::min(maxflow, cap[bef][cur] - flow[bef][cur]);
            cur = bef;
        }

        cur = end;
        while (cur != start)
        {
            auto &bef = track[cur];
            flow[bef][cur] += maxflow;
            flow[cur][bef] -= maxflow;
            cur = bef;
        }
        rtn = std::min(limit, rtn + maxflow);
    }
    return rtn;
}

void connect(int a, int b, int capacity)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
    cap[a][b] = capacity;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        connect(0, i, 1);
        int p;
        std::cin >> p;
        for (int j = 0; j < p; j++)
        {
            int w;
            std::cin >> w;
            connect(i, n + w, 1);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        connect(n + i, n + m + 1, 1);
    }

    int solve1 = solve(0, n + m + 1, m);
    for (int i = 1; i <= n; i++)
        cap[0][i] += k;
    int solve2 = solve(0, n + m + 1, k);
    std::cout << solve1 + solve2 << '\n';
}