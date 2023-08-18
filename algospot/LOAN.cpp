#include <bits/stdc++.h>
using namespace std;

bool canRepay(double amount, int month, double rates, double monthly)
{
    double left = amount;
    while (month--)
    {
        left *= (1 + (rates / 12) / 100);
        left -= monthly;
    }

    return left <= 0;
}
double solve(double amount, int month, double rates)
{
    double l = 0, r = amount * (1 + rates / 12 / 100);
    for (int i = 0; i < 100; i++)
    {
        double mid = (l + r) / 2;
        if (canRepay(amount, month, rates, mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(7);

    int t;
    cin >> t;
    while (t--)
    {
        double n, m, p;
        cin >> n >> m >> p;
        cout << solve(n, m, p) << '\n';
    }
}