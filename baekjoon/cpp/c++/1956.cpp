#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair; // dist, dest
const int INF = 0x3f3f3f3f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int v, e;
    cin >> v >> e;
    int d[v + 1][v + 1];
    memset(d, 0x3f, sizeof(int) * (v + 1) * (v + 1));
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (i != j && i != k && j != k)
                {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i != j)
                ans = min(ans, d[i][j] + d[j][i]);
        }
    }
    cout << (ans == INF ? -1 : ans);
}