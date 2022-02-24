#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt = 0;
    string s;
    map<string, int> m;
    while (getline(cin, s))
    {
        m[s]++;
        cnt++;
    }
    cout.precision(4);
    cout << fixed;
    for (auto &p : m)
    {
        double d = p.second;
        cout << p.first << ' ' << d * 100 / cnt << '\n';
    }
}