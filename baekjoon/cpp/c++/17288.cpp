#include <bits/stdc++.h>
using namespace std;

int solve(string &s)
{
    int cnt = 0, tcnt = 0, l = 0, i = 0, len = s.length();
    while (i < len)
    {
        while (i < len && s[i + 1] - s[i] == 1)
            i++;

        if (i - l == 2)
            cnt++;
        else
            i++;
        l = i;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    cout << solve(s);
}