#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[65];

void init()
{
    ll temp[65][10] = {0};
    for (int i = 0; i < 10; i++)
        temp[1][i] = 1;

    for (int i = 1; i < 64; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                temp[i + 1][k] += temp[i][j];
            }
        }
    }

    for (int i = 1; i <= 64; i++)
    {
        ll sum = 0;
        for (int j = 0; j < 10; j++)
            sum += temp[i][j];
        ans[i] = sum;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}