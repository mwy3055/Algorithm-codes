#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int num[100001];

bool contains(set<int> &s, int &n)
{
    return s.find(n) != s.end();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    int l = 0, r = 1; // [l, r)
    ll ans = 1;
    set<int> s;
    s.insert(num[0]);
    while (r <= n)
    {
        if (r == n)
        {
            break;
        }
        if (contains(s, num[r]))
        {
            s.erase(num[l++]);
        }
        else if (r <= n)
        {
            s.insert(num[r]);
            if (r != n)
                r++;
            ans += r - l;
        }
    }
    cout << ans;
}