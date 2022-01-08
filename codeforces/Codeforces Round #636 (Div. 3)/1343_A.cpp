#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        unsigned long long kk = 4;
        int n;
        cin >> n;
        for (int k = 2;; k++)
        {
            if (n % (kk - 1) == 0)
            {
                cout << n / (kk - 1) << '\n';
                break;
            }
            kk <<= 1;
        }
    }
}