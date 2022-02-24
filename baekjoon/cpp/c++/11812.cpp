#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    int k, q;

    cin >> n >> k >> q;

    for (int i = 0; i < q; i++)
    {
        int cnt;
        long long x, y;

        cin >> x >> y;

        if (k == 1)
        {
            cout << abs(x - y) << '\n';
            continue;
        }

        for (cnt = 0; x != y; cnt++)
        {
            if (x < y)
            {
                long long temp = x;
                x = y;
                y = temp;
            }
            x = (x + k - 2) / k;
        }
        cout << cnt << '\n';
    }

    return 0;
}