#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int all[101], sym[101];

void init()
{
    all[1] = 1;
    all[2] = 2;
    for (int i = 3; i <= 100; i++)
        all[i] = (all[i - 1] + all[i - 2]) % MOD;

    sym[1] = 1;
    sym[2] = 2;
    for (int i = 3; i <= 100; i++)
    {
        if (i % 2)
        {
            sym[i] = all[(i - 1) / 2] % MOD;
        }
        else
        {
            sym[i] = (all[i / 2 - 1] + all[i / 2]) % MOD;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    int c;
    cin >> c;
    while (c--)
    {
        int n;
        cin >> n;
        cout << (all[n] - sym[n] + MOD) % MOD << '\n';
    }
}