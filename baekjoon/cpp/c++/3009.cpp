#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> x(3), y(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int ax, ay;
    if (x[0] == x[1])
        ax = x[2];
    else
        ax = x[0];

    if (y[0] == y[1])
        ay = y[2];
    else
        ay = y[0];

    cout << ax << ' ' << ay;
}