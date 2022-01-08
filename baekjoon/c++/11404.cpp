#include <bits/stdc++.h>
using namespace std;

const int INF = 0x00ffffff;
int d[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //초기화
    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
            d[i][j] = INF;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    //플로이드 와샬
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
        }
        cout << '\n';
    }
}