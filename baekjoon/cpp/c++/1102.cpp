#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, p, cost[16][16], dp[1 << 16];
string s;

int getbit(string &s)
{
    int rtn = 0;
    for (auto &c : s)
    {
        if (c == 'Y')
            rtn |= 1;
        rtn <<= 1;
    }
    return rtn >> 1;
}
int getcount(int bit)
{
    int rtn = 0;
    while (bit)
    {
        if (bit & 1)
            rtn++;
        bit >>= 1;
    }
    return rtn;
}

int dfs(int bit)
{
    int &ret = dp[bit];
    if (getcount(bit) >= p)
        return ret = 0;
    if (ret != -1)
        return ret;

    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        if (bit & (1 << (n - 1 - i)))
        {
            for (int j = 0; j < n; j++)
            {
                if ((bit & (1 << (n - 1 - j))) == 0)
                    ans = min(ans, dfs(bit | (1 << (n - 1 - j))) + cost[i][j]);
            }
        }
    }
    return ret = ans;
}
void init()
{
    memset(dp, 0xff, sizeof(int) * (1 << 16));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    cin >> s >> p;
    if (p && s.find('Y') == string::npos)
    {
        cout << -1;
        return 0;
    }

    int orgbit = getbit(s);
    cout << dfs(orgbit);
}