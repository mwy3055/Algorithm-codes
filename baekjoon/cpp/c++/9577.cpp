#include <bits/stdc++.h>

using vi = std::vector<int>;

bool dfs(int cur, std::vector<vi> &times, vi &track, std::vector<bool> &visit)
{
    for (auto &t : times[cur])
    {
        if (visit[t])
            continue;
        visit[t] = true;
        if (track[t] == 0 || dfs(track[t], times, track, visit))
        {
            track[t] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector<vi> times(n + 1);
        for (int i = 0; i < m; i++)
        {
            int t1, t2, a;
            std::cin >> t1 >> t2 >> a;
            for (int j = 0; j < a; j++)
            {
                int q;
                std::cin >> q;
                for (int time = t1; time < t2; time++) // match starting time
                {
                    times[q].push_back(time);
                }
            }
        }

        int count = 0;
        vi track(100, 0);
        std::vector<bool> visit(100);
        for (int i = 1; i <= n; i++)
        {
            std::fill(visit.begin(), visit.end(), false);
            sort(times[i].begin(), times[i].end());
            times[i].erase(std::unique(times[i].begin(), times[i].end()), times[i].end()); // remove duplicate
            if (dfs(i, times, track, visit))
                count++;
        }
        if (count == n)
        {
            int ans = 0;
            for (int i = 0; i < 100; i++)
            {
                if (track[i] != 0)
                    ans = i;
            }
            std::cout << ans + 1 << '\n'; // 1 + maximun of starting time
        }
        else
        {
            std::cout << -1 << '\n';
        }
    }
}