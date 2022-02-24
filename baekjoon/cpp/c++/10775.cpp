#include <bits/stdc++.h>
using namespace std;

int g, p;
set<int> s;

bool docked(int t)
{
    auto it = s.lower_bound(-t);
    if (it == s.end())
        return false;
    else
    {
        s.erase(it);
        return true;
    }
}

void init()
{
    for (int i = 1; i <= g; i++)
        s.insert(-i);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> g >> p;
    init();
    int ans = 0;
    for (int i = 0; i < p; i++)
    {
        int t;
        cin >> t;
        if (docked(t))
            ans++;
        else
            break;
    }
    cout << ans;
}