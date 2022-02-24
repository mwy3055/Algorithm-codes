#include <bits/stdc++.h>
using namespace std;

int ans, n;
vector<int> rdown;
bool canput[10][10];

bool is_promising(int i)
{
    for (auto &ldown : rdown)
        if (ldown == i)
            return false;
    return true;
}
void solve(int cnt, int cur) // 'cur'th right-down diagnoal
{
    if (cur == 2 * n)
    {
        ans = max(ans, cnt);
        return;
    }

    static int d[2] = {1, 1};
    int sy, sx, limit = n - abs(n - cur);
    if (cur <= n)
    {
        sy = n - cur;
        sx = 0;
    }
    else
    {
        sy = 0;
        sx = cur - n;
    }

    bool anywhere = true; // can't put on a bishop anywhere?
    for (int i = 0; i < limit; i++)
    {
        if (canput[sy][sx] && is_promising(sy + sx + 1))
        {
            anywhere = false;
            rdown.push_back(sy + sx + 1);
            solve(cnt + 1, cur + 1);
            rdown.pop_back();
        }
        sy += d[0], sx += d[1];
    }
    if (anywhere)
    {
        solve(cnt, cur + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> canput[i][j];

    solve(0, 1);
    cout << ans;
}