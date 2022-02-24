#include <bits/stdc++.h>

const int INF = 0x3F3F3F3F;
int n, m, l, src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
std::string s;
char map[100][101];
bool visit[100][100];
int ans, r, c;

bool isin(int i, int j)
{
    return 0 <= i && i < n && 0 <= j && j < m;
}

void search(int y, int x, int dep)
{
    if (dep % l == 0 && ans < dep / l)
    {
        ans = dep / l;
        r = y, c = x;
    }
    if (visit[y][x])
    {
        ans = INF;
        return;
    }

    visit[y][x] = true;
    int nidx = dep % l;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + src[i][0], nx = x + src[i][1];
        if (isin(ny, nx) && map[ny][nx] == s[nidx])
        {
            search(ny, nx, dep + 1);
        }
    }
    visit[y][x] = false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> l >> s;
    for (int i = 0; i < n; i++)
        std::cin >> map[i];

    search(0, 0, 1);
    if (ans == 0 || ans == INF)
        std::cout << -1 << '\n';
    else
        std::cout << ans << '\n'
                  << r + 1 << ' ' << c + 1 << '\n';
}