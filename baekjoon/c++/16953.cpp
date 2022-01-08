#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 1;
void push(queue<ll> &q, set<ll> &s, ll n)
{
    if (0 < n && s.find(n) == s.end())
    {
        q.push(n);
        s.insert(n);
    }
}
ll solve(int a, int b)
{
    queue<ll> q;
    set<ll> s;

    ll ans = 0;
    q.push(a);
    s.insert(a);
    while (!q.empty())
    {
        ans++;
        ll siz = q.size();
        bool issmall = false;
        while (siz--)
        {
            ll top = q.front();
            q.pop();
            if (top == b)
                return ans;
            if (top < b)
                issmall = true;

            if (top < INF)
            {
                push(q, s, top * 2);
                push(q, s, top * 10 + 1);
            }
        }
        if (!issmall)
            break;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    cout << solve(a, b);
}