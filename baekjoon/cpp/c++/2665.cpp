#include <bits/stdc++.h>

struct node
{
    int r, c, broke;
    node(int r, int c, int broke = 0) : r(r), c(c), broke(broke) {}
};

int n;
std::string map[50];
int visit[50][50];

int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> map[i];
    }
}

bool isin(int r, int c)
{
    return 0 <= r && r < n &&
           0 <= c && c < n;
}

int solve()
{
    std::memset(visit, 0x3f, sizeof(visit));
    std::queue<node> q;

    q.emplace(0, 0, 0);
    visit[0][0] = 0;
    while (!q.empty())
    {
        auto [r, c, broke] = q.front();
        q.pop();

        if (r == n - 1 && c == n - 1)
        {
            continue;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i], nc = c + dc[i];
            if (isin(nr, nc))
            {
                int nbroke = broke + (map[nr][nc] == '0');
                if (nbroke < visit[nr][nc])
                {
                    q.emplace(nr, nc, nbroke);
                    visit[nr][nc] = nbroke;
                }
            }
        }
    }
    return visit[n - 1][n - 1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}