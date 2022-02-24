#include <bits/stdc++.h>
using namespace std;

bool crack[2000001];

void check(int &p, int &c)
{
    int t = p;
    do
    {
        crack[t] = true;
        t += p;
    } while (t <= c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    while (n--)
    {
        int period;
        cin >> period;
        check(period, c);
    }

    int ans = 0;
    for (int i = 1; i <= c; i++)
        if (crack[i])
            ans++;
    cout << ans;
}