#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
struct camera
{
    int y, x, type, dir;
    camera(int y, int x, int type) : y(y), x(x), type(type), dir(0) {}
};
int n, m, room[8][8], ans, tsize;
vector<camera> cameras;
vector<pii> dir = {pii(0, 1), pii(1, 0), pii(0, -1), pii(-1, 0)};
vector<vector<int>> cansee[6];

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}
void check()
{
    bool croom[8][8] = {false};
    for (auto &c : cameras)
    {
        for (auto &p : cansee[c.type][c.dir])
        {
            int cy = c.y, cx = c.x;
            while (isin(cy, cx) && room[cy][cx] != 6)
            {
                croom[cy][cx] = true;
                cy += dir[p].first, cx += dir[p].second;
            }
        }
    }

    int able = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (croom[i][j])
                able++;
    ans = min(ans, tsize - able);
}
void solve(int idx)
{
    if (idx == cameras.size())
    {
        check();
        return;
    }

    for (int i = 0; i < cansee[cameras[idx].type].size(); i++)
    {
        cameras[idx].dir = i;
        solve(idx + 1);
    }
}

void makedata()
{
    cansee[1] = {{0}, {1}, {2}, {3}};
    cansee[2] = {{0, 2}, {1, 3}};
    cansee[3] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    cansee[4] = {{0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1}};
    cansee[5] = {{0, 1, 2, 3}};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    makedata();

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> room[i][j];
            if (0 < room[i][j] && room[i][j] < 6)
            {
                cameras.push_back(camera(i, j, room[i][j]));
            }
            if (room[i][j] < 6)
                tsize++;
        }
    }

    ans = tsize;
    solve(0);
    cout << ans;
}