#include <bits/stdc++.h>

using vi = std::vector<int>;

struct segment
{
    int x, y, len, val = 0;
};
const int MAX_DEP = 22, MAX = (1 << MAX_DEP) - 1, IDENTITY = 0;
segment tree[MAX];
int n, d[][2] = {0, 0, 0, 1, 1, 0, 1, 1};

bool isin(int x, int y, int len, int tx, int ty)
{
    return x <= tx && tx <= x + len - 1 && y <= ty && ty <= y + len - 1;
}

int maketree(int idx, int x, int y, int len, std::vector<vi> &arr)
{
    auto &now = tree[idx];
    now.x = x, now.y = y, now.len = len;
    if (len == 1)
    {
        if (x < n && y < n)
            now.val = arr[x][y];
        else
            now.val = IDENTITY;
    }
    else
    {
        int nlen = len / 2;
        for (int i = 0; i < 4; i++)
        {
            int result = maketree(4 * idx + (i + 1), x + nlen * d[i][0], y + nlen * d[i][1], nlen, arr);
            now.val += result;
        }
    }
    return now.val;
}

int updateval(int idx, int &tx, int &ty, int &val)
{
    auto &x = tree[idx].x, &y = tree[idx].y, &len = tree[idx].len, &cval = tree[idx].val;
    if (x == tx && y == ty && len == 1)
    {
        cval = val;
    }
    else if (!isin(x, y, len, tx, ty))
    {
        ;
    }
    else
    {
        int rtn = 0;
        for (int i = 0; i < 4; i++)
        {
            int result = updateval(4 * idx + (i + 1), tx, ty, val);
            rtn += result;
        }
        cval = rtn;
    }
    return cval;
}
int getval(int idx, int sx, int sy, int ex, int ey)
{
    auto &x = tree[idx].x, &y = tree[idx].y, &len = tree[idx].len;
    if (sx <= x && x + len - 1 <= ex && sy <= y && y + len - 1 <= ey)
    {
        return tree[idx].val;
    }
    else if ((ex < x || ey < y) || (x + len - 1 < sx || y + len - 1 < sy))
    {
        return IDENTITY;
    }
    else
    {
        int rtn = 0;
        for (int i = 1; i <= 4; i++)
        {
            int result = getval(4 * idx + i, sx, sy, ex, ey);
            rtn += result;
        }
        return rtn;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int m;
    std::cin >> n >> m;
    std::vector<vi> arr(n, vi(n));
    for (auto &row : arr)
        for (auto &col : row)
            std::cin >> col;
    maketree(0, 0, 0, 1024, arr);

    for (int i = 0; i < m; i++)
    {
        int w;
        std::cin >> w;
        if (w == 0)
        {
            int x, y, c, target;
            std::cin >> x >> y >> c;
            updateval(0, --x, --y, c);
        }
        else
        {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << getval(0, --x1, --y1, --x2, --y2) << '\n';
        }
    }
}