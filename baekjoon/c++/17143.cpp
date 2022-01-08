#include <bits/stdc++.h>
using namespace std;

struct shark
{
    int r, c, s, d, z;
};

int mv[][2] = {0, 0, -1, 0, 1, 0, 0, 1, 0, -1};
int r, c, m;
deque<shark> grid[101][101];

int ifwall(shark &s, int dir)
{
    int sr = s.r + mv[dir][0], sc = s.c + mv[dir][1];
    if (!(1 <= sr && sr <= r && 1 <= sc && sc <= c))
    {
        if (dir == 1)
            return 2;
        else if (dir == 2)
            return 1;
        else if (dir == 3)
            return 4;
        else if (dir == 4)
            return 3;
        else
            return -1;
    }

    return dir;
}

void move()
{
    queue<shark> q;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (!grid[i][j].empty())
            {
                q.push(grid[i][j].front());
                grid[i][j].pop_front();
            }
        }
    }
    while (!q.empty())
    {
        shark s = q.front();
        q.pop();
        int speed = s.s, dir = s.d;
        // how to calculate directly?
        while (speed--)
        {
            dir = ifwall(s, dir);
            s.r += mv[dir][0], s.c += mv[dir][1];
        }
        s.d = dir;
        grid[s.r][s.c].push_back(s);
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (1 < grid[i][j].size())
            {
                shark s = grid[i][j].front();
                for (auto &sharks : grid[i][j])
                {
                    if (s.z < sharks.z)
                    {
                        s = sharks;
                    }
                }
                grid[i][j].clear();
                grid[i][j].push_back(s);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> m;
    for (int i = 0; i < m; i++)
    {
        shark s;
        cin >> s.r >> s.c >> s.s >> s.d >> s.z;
        if (s.d < 3)
            s.s %= 2 * r - 2;
        else
            s.s %= 2 * c - 2;
        grid[s.r][s.c].push_back(s);
    }

    int fisher = 0, ans = 0;
    while (fisher < c)
    {
        fisher++;

        int tc = 1;
        while (tc <= r && grid[tc][fisher].empty())
            tc++;
        if (tc <= r)
        {
            shark catched = grid[tc][fisher].front();
            grid[tc][fisher].pop_front();
            ans += catched.z;
        }

        move();
    }

    cout << ans;
}