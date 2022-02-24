#include <bits/stdc++.h>
using namespace std;

int d[501][501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a][b] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && j != k && i != k)
                    d[i][j] |= d[i][k] & d[k][j];
            }
        }
    }

    int s;
    cin >> s;
    for (int i = 0; i < s; i++)
    {
        int a, b, ans;
        cin >> a >> b;
        if (d[a][b])
            ans = -1;
        else if (d[b][a])
            ans = 1;
        else
        {
            ans = 0;
        }
        cout << ans << '\n';
    }
}