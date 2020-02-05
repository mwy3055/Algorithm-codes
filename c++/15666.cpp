#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> push, cleaned;

void solve(int idx, int left) //골라야 하는 숫자의 수
{
    if (left == 0)
    {
        for (auto &p : push)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < n; i++)
    {
        push.push_back(cleaned[i]);
        solve(i, left - 1);
        push.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (find(cleaned.begin(), cleaned.end(), t) == cleaned.end())
            cleaned.push_back(t);
    }
    sort(cleaned.begin(), cleaned.end());
    n = cleaned.size();

    solve(0, m);
}