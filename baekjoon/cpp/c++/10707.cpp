#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, p;
    cin >> a >> b >> c >> d >> p;
    cout << min(a * p, (p <= c ? b : b + (p - c) * d));
}