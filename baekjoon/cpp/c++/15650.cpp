#include <bits/stdc++.h>
using namespace std;

int n, m;
bool ispush[9] = {false};
vector<int> push;

void solve(int dep, int left) //재귀 깊이, 골라야 하는 숫자의 수
{
    if (left == 0)
    {
        for (auto &p : push)
            cout << p << ' ';
        cout << '\n';
        return;
    }

    int start = (dep == 1 ? 1 : push.back());
    for (int i = start; i <= n; i++)
    {
        if (!ispush[i])
        {
            ispush[i] = true;
            push.push_back(i);
            solve(dep + 1, left - 1);
            ispush[i] = false;
            push.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    solve(1, m);
}