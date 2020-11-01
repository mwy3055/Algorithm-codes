#include <bits/stdc++.h>

using ll = long long;
ll tree[1000001];
int n, m, k;

void update(int idx, int diff)
{
    while (idx <= n)
    {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}
ll sum(int e)
{
    ll ret = 0;
    while (e > 0)
    {
        ret += tree[e];
        e -= (e & -e);
    }
    return ret;
}
ll sum(int s, int e)
{
    return sum(e) - sum(s - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        update(i + 1, num);
    }

    for (int i = 0; i < m + k; i++)
    {
        int a;
        std::cin >> a;
        if (a == 1)
        {
            int b, c, d;
            std::cin >> b >> c >> d;
            for (int i = b; i <= c; i++)
                update(i, d);
        }
        else
        {
            int b, c;
            std::cin >> b >> c;
            std::cout << sum(b, c) << '\n';
        }
    }
}