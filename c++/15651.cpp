#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> push;

void solve(int left) //골라야 하는 숫자의 수
{
    if (left == 0)
    {
        for (auto &p : push)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        push.push_back(i);
        solve(dep + 1, left - 1);
        push.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    solve(m);
}