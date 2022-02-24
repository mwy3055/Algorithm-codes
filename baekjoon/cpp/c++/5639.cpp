#include <bits/stdc++.h>
using namespace std;

typedef vector<int>::iterator viit;
vector<int> node;

void solve(viit l, viit r) // [l, r)
{
    if (l == r)
        return;

    int value = *l;
    if (++l != r)
    {
        viit begin_right = lower_bound(l, r, value);
        solve(l, begin_right);
        solve(begin_right, r);
    }
    cout << value << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    while (cin >> t)
    {
        node.push_back(t);
    }

    solve(node.begin(), node.end());
}