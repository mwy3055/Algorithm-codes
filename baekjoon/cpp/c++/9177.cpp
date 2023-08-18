#include <bits/stdc++.h>
using namespace std;

string a, b, c;
int dp[201][201];

void init(int alen, int blen)
{
    for (int i = 0; i <= alen; i++)
        memset(dp + i, -1, sizeof(int) * (blen + 1));
}
bool solve(int aidx, int bidx, int cidx)
{
    int &ret = dp[aidx][bidx];
    if (aidx == a.length() && bidx == b.length())
        return ret = 1;
    if (ret != -1)
        return ret;

    bool ans = false;
    if (aidx < a.length() && a[aidx] == c[cidx])
        ans |= solve(aidx + 1, bidx, cidx + 1);
    if (bidx < b.length() && b[bidx] == c[cidx])
        ans |= solve(aidx, bidx + 1, cidx + 1);
    return ret = ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        init(a.length(), b.length());
        bool ans = solve(0, 0, 0);
        cout << "Data set " << i << ": " << (ans ? "yes" : "no") << '\n';
    }
}