#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(d, 0x3f, sizeof(d));

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a][b] = d[b][a] = 1;
    }

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

    int minv = 0x3f3f3f3f, minidx;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                sum += d[i][j];
        }
        if (sum < minv)
        {
            minv = sum;
            minidx = i;
        }
    }

    cout << minidx;
}