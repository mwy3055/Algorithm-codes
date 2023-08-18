#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, m, visit[1000][1000];
char map[1000][1001];

int search(int r, int c, int count)
{
    if (visit[r][c])
        return 0;

    while (!visit[r][c])
    {
        visit[r][c] = count;
        switch (map[r][c])
        {
        case 'U':
            r -= 1;
            break;
        case 'D':
            r += 1;
            break;
        case 'L':
            c -= 1;
            break;
        case 'R':
            c += 1;
            break;
        }
    }
    return visit[r][c] == count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> map[i][j];
        }
    }

    int ans = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += search(i, j, ++count);
        }
    }
    std::cout << ans << '\n';
}