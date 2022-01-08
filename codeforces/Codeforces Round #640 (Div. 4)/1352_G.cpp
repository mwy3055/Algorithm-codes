#include <bits/stdc++.h>
using namespace std;

bool solve(int idx, int prevval, int &n, vector<int> &ans, vector<bool> &used)
{
    if (idx == n)
    {
        for (auto &a : ans)
            cout << a << ' ';
        cout << '\n';
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (prevval == -1 || (!used[i] && 2 <= abs(prevval - i) && abs(prevval - i) <= 4))
        {
            ans.push_back(i);
            used[i] = true;
            if (solve(idx + 1, i, n, ans, used))
                return true;
            ans.pop_back();
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        vector<bool> used(n + 1, false);
        if (!solve(0, -1, n, ans, used))
            cout << -1 << '\n';
    }
}