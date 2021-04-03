#include <bits/stdc++.h>

bool map[10][10], tmap[10][10];
int n = 10, dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};
const int INF = 1e9;

void getinput()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            std::cin >> c;
            if (c == 'O')
                map[i][j] = true;
        }
    }
}

bool isin(int r, int c)
{
    return (0 <= r && r < n) && (0 <= c && c < n);
}

void pull(int r, int c)
{
    tmap[r][c] = !tmap[r][c];
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i], nc = c + dc[i];
        if (isin(nr, nc))
            tmap[nr][nc] = !tmap[nr][nc];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();

    // state: 첫 줄의 각 스위치를 눌러야 하는가? (비트마스크)
    // 1. 첫번째 줄만 임의로 정하고
    // 2. 두번째 줄부터는 바로 윗 줄 스위치가 켜져 있다면 누르는 방식으로 진행한다.
    //    이렇게 하면 맨 마지막 줄을 제외한 모든 스위치는 꺼져 있게 된다.
    // 3. 모든 스위치가 꺼져 있다면 정답의 후보가 된다. 후보 중 가장 작은 값을 찾자.
    int ans = INF;
    for (int state = 0; state < (1 << n); state++)
    {
        memcpy(tmap, map, sizeof(map));
        int tans = 0;
        // 1
        for (int c = 0; c < n; c++)
        {
            if (state & (1 << c))
            {
                tans++;
                pull(0, c);
            }
        }
        // 2
        for (int r = 1; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (tmap[r - 1][c])
                {
                    tans++;
                    pull(r, c);
                }
            }
        }
        // 3
        int on_count = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                on_count += tmap[r][c];
            }
        }
        if (!on_count)
            ans = std::min(ans, tans);
    }
    std::cout << (ans == INF ? -1 : ans) << '\n';
}