#include <bits/stdc++.h>
using namespace std;

int num[8], n, m;

bool nondescending(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
        if (num[v[i]] > num[v[i + 1]])
            return false;
    return true;
}
void solve(int dep, vector<int> &v)
{
    if (v.size() == m && nondescending(v))
    {
        for (auto &idx : v)
            cout << num[idx] << ' ';
        cout << '\n';
        return;
    }
    if (dep == n)
        return;

    for (int i = 0; i < n; i++)
    {
        v.push_back(i);
        solve(dep + 1, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    vector<int> v;
    solve(0, v);
}