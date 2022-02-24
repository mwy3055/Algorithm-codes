#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
bool ispalin[2500][2500];
string s;
int len, dp[2500];

void init()
{
    len = s.length();
    for (int i = 0; i < len; i++)
        ispalin[i][i] = true;
    for (int i = 0; i < len - 1; i++)
        ispalin[i][i + 1] = (s[i] == s[i + 1]);
    for (int k = 2; k <= len - 1; k++)
    {
        for (int i = 0; i <= len - k; i++)
        {
            // i + k¹øÂ° Ä­
            int j = i + k;
            if (s[i] == s[j] && ispalin[i + 1][j - 1])
                ispalin[i][j] = true;
        }
    }
}
int solve(int l)
{
    if (l >= len)
        return 0;
    int &ret = dp[l];
    if (ret)
        return ret;

    ret = INF;
    for (int i = l; i < len; i++)
    {
        if (ispalin[l][i])
            ret = min(ret, 1 + solve(i + 1));
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    init();
    /*
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            cout << "(" << i << ", " << j << "): " << ispalin[i][j] << ' ';
        }
        cout << '\n';
    }*/
    cout << solve(0);
}