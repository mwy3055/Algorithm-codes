#include <bits/stdc++.h>
using namespace std;

//가장 넓은 빈 공간을 찾자
int solve(int &n, int &m, int *loc)
{
    if (m == 1)
        return max(loc[0], n - loc[0]);

    int ans = loc[0];
    for (int i = 1; i < m; i++)
    {
        int tgap = loc[i] - loc[i - 1];
        if (ans < tgap / 2 + tgap % 2)
            ans = tgap / 2 + tgap % 2;
    }

    int tgap = n - loc[m - 1];
    if (ans < tgap)
        ans = tgap;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int loc[m];
    for (int i = 0; i < m; i++)
        cin >> loc[i];

    cout << solve(n, m, loc);
}