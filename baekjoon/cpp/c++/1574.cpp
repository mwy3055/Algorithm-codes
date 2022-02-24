#include <bits/stdc++.h>

using vi = std::vector<int>;
vi graph[301], track(301);
std::vector<bool> visit(301);
bool empty[301][301];

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

void getinput(int &r, int &c, int &n)
{
    bool rotate = false;
    std::cin >> r >> c >> n;
    if (r > c)
    {
        std::swap(r, c); // make r <= c
        rotate = true;
    }
    for (int i = 0; i < n; i++)
    {
        int row, col;
        std::cin >> row >> col;
        if (rotate)
        {
            std::swap(row, col);
        }
        empty[row][col] = true;
    }
}

void makegraph(int &r, int &c)
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!empty[i][j])
            {
                graph[i].push_back(j);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    // assume r <= c
    // if not: rotate the board
    int r, c, n;
    getinput(r, c, n);
    makegraph(r, c);

    // try to place rook at each row
    int ans = 0;
    for (int i = 1; i <= r; i++)
    {
        std::fill(visit.begin(), visit.end(), false);
        if (dfs(i))
            ans++;
    }
    std::cout << ans << '\n';
}