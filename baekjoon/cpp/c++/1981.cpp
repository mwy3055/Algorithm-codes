#include <bits/stdc++.h>
using namespace std;

struct node
{
    int max, min, y, x, pry, prx;
    node(int max, int min, int y, int x, int pry, int prx) : max(max), min(min), y(y), x(x), pry(pry), prx(prx) {}
    bool operator>(node n) const
    {
        int diff1 = ((this->max) - (this->min)), diff2 = (n.max - n.min);
        if (diff1 == diff2)
            return ((this->y == n.y) ? (this->x < n.x) : (this->y < n.y));
        return diff1 > diff2;
    }
};
typedef pair<int, int> coord;
int n, arr[100][100], diff[100][100], src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int cmax = 0, cmin = 200;
bool visit[100][100];

void bfsinit()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visit[i][j] = false;
}
bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool bfs(int minval, int d)
{
    bfsinit();
    queue<coord> q;

    if (minval <= arr[0][0] && arr[0][0] <= minval + d)
    {
        visit[0][0] = true;
        q.push(coord(0, 0));
    }
    while (!q.empty())
    {
        auto top = q.front();
        auto &y = top.first, &x = top.second;
        q.pop();

        if (y == n - 1 && x == n - 1)
            return true;
        for (int i = 0; i < 4; i++)
        {
            int ny = y + src[i][0], nx = x + src[i][1];
            if (isin(ny, nx) && !visit[ny][nx] && (minval <= arr[ny][nx] && arr[ny][nx] <= minval + d))
            {
                visit[ny][nx] = true;
                q.push(coord(ny, nx));
            }
        }
    }
    return false;
}
bool cango(int d)
{
    for (int i = cmin; i <= cmax; i++)
    {
        if (bfs(i, d))
            return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < 100; i++)
        memset(diff + i, 0x6f, sizeof(int) * 100);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            cmax = max(cmax, arr[i][j]);
            cmin = min(cmin, arr[i][j]);
        }
    }

    int left = 0, right = cmax - cmin, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (cango(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << (cango(left) ? left : left - 1);
}