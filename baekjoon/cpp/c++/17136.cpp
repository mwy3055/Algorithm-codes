#include <bits/stdc++.h>
using namespace std;

const int MAX = 16;

bool paper[10][10], covered[10][10];
int avail[5] = {5, 5, 5, 5, 5};
int ans = MAX;

bool is_covered()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (paper[i][j] && !covered[i][j])
                return false;
        }
    }
    return true;
}

bool cancover(int y, int x, int i)
{
    if ((10 <= y + i) || (10 <= x + i))
        return false;
    for (int ty = 0; ty <= i; ty++)
    {
        for (int tx = 0; tx <= i; tx++)
        {
            if (!(paper[y + ty][x + tx] && !covered[y + ty][x + tx]))
                return false;
        }
    }
    return true;
}
void cover(int y, int x, int i)
{
    for (int ty = 0; ty <= i; ty++)
        for (int tx = 0; tx <= i; tx++)
            covered[y + ty][x + tx] = true;
}
void uncover(int y, int x, int i)
{
    for (int ty = 0; ty <= i; ty++)
        for (int tx = 0; tx <= i; tx++)
            covered[y + ty][x + tx] = false;
}

void solve(int y, int x, int dep)
{
    if (ans <= dep)
    {
        return;
    }

    int cy, cx;
    for (cy = y; cy < 10; cy++)
    {
        bool find = false;
        for (cx = (cy == y ? x : 0); cx < 10; cx++)
        {
            if (paper[cy][cx] && !covered[cy][cx])
            {
                find = true;
                break;
            }
        }
        if (find)
            break;
    }

    if (cy == 10 && cx == 10)
    {
        ans = min(ans, dep);
        return;
    }

    for (int siz = 4; siz >= 0; siz--)
    {
        if (cancover(cy, cx, siz) && 0 < avail[siz])
        {
            avail[siz]--;
            cover(cy, cx, siz);
            solve(cy, cx + siz + 1, dep + 1);
            uncover(cy, cx, siz);
            avail[siz]++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> paper[i][j];

    solve(0, 0, 0);
    cout << (ans == MAX ? -1 : ans);
}