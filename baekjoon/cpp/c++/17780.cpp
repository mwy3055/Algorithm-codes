#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int> horse; // index, y, x, dir
int n, k, board[13][13];
vector<int> onboard[13][13];
vector<horse> horses;

bool isin(int y, int x)
{
    return 1 <= y && y <= n && 1 <= x && x <= n;
}
bool move(horse &h)
{
    static int src[][2] = {0, 0, 0, 1, 0, -1, -1, 0, 1, 0};
    static int opposite[] = {0, 2, 1, 4, 3};

    int idx, y, x, dir;
    tie(idx, y, x, dir) = h;

    if (onboard[y][x][0] != idx)
        return false;

    auto it = find(onboard[y][x].begin(), onboard[y][x].end(), idx);
    vector<int> moving;
    for (auto i = it; i != onboard[y][x].end(); i++)
        moving.push_back(*i);
    onboard[y][x].erase(it, onboard[y][x].end());

    int sy = y + src[dir][0], sx = x + src[dir][1];
    if (!isin(sy, sx) || board[sy][sx] == 2) // blue
    {
        dir = opposite[dir];
        sy = y + src[dir][0], sx = x + src[dir][1];
        if (!isin(sy, sx) || board[sy][sx] == 2)
        {
            sy = y, sx = x;
        }
        else if (board[sy][sx] == 1)
            reverse(moving.begin(), moving.end());
    }
    else if (board[sy][sx] == 1) // red
        reverse(moving.begin(), moving.end());

    for (auto &m : moving)
    {
        onboard[sy][sx].push_back(m);
        get<1>(horses[m]) = sy, get<2>(horses[m]) = sx;
    }
    get<3>(h) = dir;

    if (onboard[sy][sx].size() >= 4)
        return true;
    return false;
}
bool solve() // return true if game is finished
{
    for (auto &h : horses)
    {
        if (move(h))
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    for (int i = 0; i < k; i++)
    {
        int y, x, dir;
        cin >> y >> x >> dir;
        horses.push_back(horse(i, y, x, dir));
        onboard[y][x].push_back(i);
    }

    for (int i = 1; i <= 1000; i++)
    {
        if (solve())
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}