#include <bits/stdc++.h>
using namespace std;

int n, k, maxdep, dp[1000001][10];

string itos(int i)
{
    string rtn;
    do
    {
        rtn.push_back('0' + i % 10);
        i /= 10;
    } while (i);
    reverse(rtn.begin(), rtn.end());
    return rtn;
}
int stoi(string &s)
{
    int rtn = 0;
    for (auto &c : s)
        rtn = rtn * 10 + (c - '0');
    return rtn;
}
int solve(int cur, int dep)
{
    if (dep == k)
    {
        maxdep = dep;
        return cur;
    }
    int &ret = dp[cur][dep];
    if (ret != -1)
        return ret;

    ret = 0;
    maxdep = max(maxdep, dep);
    string s = itos(cur);
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            if (i == 0 && s[j] == '0')
                continue;
            string t = s;
            swap(t[i], t[j]);
            int next = stoi(t);
            ret = max(ret, solve(next, dep + 1));
        }
    }
    return ret;
}
void init()
{
    for (int i = 0; i < 1000001; i++)
        memset(dp + i, -1, sizeof(int) * 10);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n >> k;
    int ans = solve(n, 0);
    if (maxdep == k)
        cout << ans;
    else
        cout << -1;
}