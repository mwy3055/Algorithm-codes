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

    int start = (push.empty() ? 1 : push.back());
    for (int i = start; i <= n; i++)
    {
        push.push_back(i);
        solve(left - 1);
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