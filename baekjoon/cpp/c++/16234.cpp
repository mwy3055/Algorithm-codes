#include <bits/stdc++.h>
using namespace std;

int n, l, r, board[50][50];
set<int> opened[50][50];

const int MAX = 2500;
int root[MAX + 1];
void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}
int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}
void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}

bool isin(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}
bool isopen(int &y1, int &x1, int &y2, int &x2)
{
    int diff = abs(board[y1][x1] - board[y2][x2]);
    return l <= diff && diff <= r;
}
bool move()
{
    static int src[][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    bool finished = true;
    init();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            opened[i][j].clear();
            for (int k = 0; k < 4; k++)
            {
                int sy = i + src[k][0], sx = j + src[k][1];
                int n1 = i * n + j, n2 = sy * n + sx;
                if (isin(sy, sx) && isopen(i, j, sy, sx) && (find(n1) != find(n2)))
                {
                    union_vertex(n1, n2);
                    finished = false;
                }
            }
        }
    }

    if (finished)
        return true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int par = find(i * n + j);
            int py = par / n, px = par % n;
            opened[py][px].insert(i * n + j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0, siz = opened[i][j].size();
            for (auto &u : opened[i][j]) // union
            {
                int uy = u / n, ux = u % n;
                sum += board[uy][ux];
            }
            for (auto &u : opened[i][j]) // union
            {
                int uy = u / n, ux = u % n;
                board[uy][ux] = sum / siz;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    int ans = 0;
    while (!move())
        ans++;
    cout << ans;
}