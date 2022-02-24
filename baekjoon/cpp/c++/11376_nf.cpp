#include <bits/stdc++.h>

using vi = std::vector<int>;

// [0]: start
// [1, n]: employee
// [n + 1, n + m]: work
// [n + m + 1]: end
vi graph[2002];
int capacity[2002][2002], flow[2002][2002];

int solve(int start, int end)
{
    vi track(end + 1);
    int ans = 0;
    while (true)
    {
        std::fill(track.begin(), track.end(), -1);

        std::queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto &adj : graph[top])
            {
                if (flow[top][adj] < capacity[top][adj] && track[adj] == -1)
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
        int minflow = 0x3f3f3f3f, cur = end;
        while (cur != start)
        {
            auto before = track[cur];
            minflow = std::min(minflow, capacity[before][cur] - flow[before][cur]);
            cur = before;
        }

        cur = end;
        while (cur != start)
        {
            auto before = track[cur];
            flow[before][cur] += minflow;
            flow[cur][before] -= minflow;
            cur = before;
        }
        ans += minflow;
    }
    return ans;
}

void makeEdge(int from, int to, int cap)
{
    graph[from].push_back(to);
    graph[to].push_back(from);
    capacity[from][to] = cap;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        makeEdge(0, i, 2);
        int s;
        std::cin >> s;
        for (int j = 0; j < s; j++)
        {
            int num;
            std::cin >> num;
            makeEdge(i, n + num, 1);
        }
    }
    for (int i = 1; i <= m; i++)
        makeEdge(n + i, n + m + 1, 1);

    std::cout << solve(0, n + m + 1) << '\n';
}