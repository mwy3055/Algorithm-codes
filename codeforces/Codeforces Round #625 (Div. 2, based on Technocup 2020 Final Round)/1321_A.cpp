#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool r1[100], r2[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r1[i];
    for (int i = 0; i < n; i++)
        cin >> r2[i];

    int rr1 = 0, rr2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (r1[i] && !r2[i])
            rr1++;
        else if (r2[i] && !r1[i])
            rr2++;
    }

    if (rr1 == 0 || rr2 == n)
        cout << -1;
    else
        cout << (rr2 / rr1) + 1;
}