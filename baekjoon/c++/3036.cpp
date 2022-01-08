#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i];

    for (int i = 1; i < n; i++)
    {
        int gcd = GCD(r[0], r[i]);
        cout << r[0] / gcd << '/' << r[i] / gcd << '\n';
    }
}
