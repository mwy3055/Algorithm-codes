#include <bits/stdc++.h>

using vi = std::vector<int>;
char map[50][51];
std::vector<vi> row(50, vi(50)), col(50, vi(50));
vi graph[2501], track(2501);
std::vector<bool> visit(2501, false);

int setnumber(int &n, int &m)
{
    // row
    int rcnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;)
        {
            if (map[i][j] == '*')
            {
                while (j < m && map[i][j] == '*')
                {
                    row[i][j++] = rcnt;
                }
                rcnt++;
            }
            else
                j++;
        }
    }

    int ccnt = 1;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n;)
        {
            if (map[i][j] == '*')
            {
                while (i < n && map[i][j] == '*')
                {
                    col[i++][j] = ccnt;
                }
                ccnt++;
            }
            else
                i++;
        }
    }

    return std::max(rcnt, ccnt) - 1;
}

bool dfs(int cur)
{
    for (auto &adj : graph[cur])
    {
        if (visit[adj])
            continue;
        visit[adj] = true;
        if (track[adj] == 0 || dfs(track[adj]))
        {
            track[adj] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        std::cin >> map[i];

    int num = setnumber(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            auto &r = row[i][j], &c = col[i][j];
            if (r != 0)
            {
                graph[r].push_back(c);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= num; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
}