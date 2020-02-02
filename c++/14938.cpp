#include <bits/stdc++.h>
using namespace std;

const int INF = 0x00ffffff;
int d[101][101];

void init()
{
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
}
void floyd_warshall(int &n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && i != k && j != k)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
}
int getitem(int *item, int &i, int &n, int &m)
{
    vector<int> v;
    for (int c = 1; c <= n; c++)
    {
        if (d[c][i] <= m)
            v.push_back(c);
    }

    int cnt = 0;
    for (auto &site : v)
        cnt += item[site];
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int n, m, r;
    cin >> n >> m >> r;
    int item[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> item[i];
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        d[a][b] = d[b][a] = l;
    }

    floyd_warshall(n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, getitem(item, i, n, m));
    }
    cout << ans;
}