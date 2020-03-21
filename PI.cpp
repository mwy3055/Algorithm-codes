#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
vector<int> dp(10001);

int diff(int &cur, int &len, string &s)
{
    bool allsame = true, mono = true, alternate = true, eqdiff = true;
    for (int i = cur; i < cur + len; i++)
    {
        if (s[i] != s[cur])
            allsame = false;
        if (cur < i && i < cur + len - 1 && !((s[i - 1] - s[i] == s[i] - s[i + 1] && abs(s[i - 1] - s[i]) == 1)))
            mono = false;
        if (s[i] != s[cur % 2 == i % 2 ? cur : cur + 1])
            alternate = false;
        if (cur < i && i < cur + len - 1 && s[i - 1] - s[i] != s[i] - s[i + 1])
            eqdiff = false;
    }
    if (allsame)
        return 1;
    if (mono)
        return 2;
    if (alternate)
        return 4;
    if (eqdiff)
        return 5;
    return 10;
}
int solve(int cur, string &s)
{
    int &ret = dp[cur];
    if (ret != -1)
        return ret;
    if (s.length() <= cur)
        return ret = 0;

    ret = INF;
    for (int i = 3; i <= 5; i++)
    {
        if (cur + i <= s.length())
            ret = min(ret, solve(cur + i, s) + diff(cur, i, s));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        fill(dp.begin(), dp.end(), -1);
        string s;
        cin >> s;
        cout << solve(0, s) << '\n';
    }
}