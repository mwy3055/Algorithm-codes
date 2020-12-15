#include <bits/stdc++.h>

using ll = long long;

const int SIZE = (1 << 21) + 1;
ll fenwick[SIZE];
ll getsum(ll i) // get sum of interval [1, i]
{
    ll sum = 0;
    while (i > 0)
    {
        sum += fenwick[i];
        i -= i & -i;
    }
    return sum;
}

void add(ll i, ll val) // increase num[i] by val
{
    while (i < SIZE)
    {
        fenwick[i] += val;
        i += i & -i;
    }
}

ll arr[1000001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int fun;
        std::cin >> fun;
        if (fun == 0)
        {
            int i, j;
            std::cin >> i >> j;
            if (i > j)
                std::swap(i, j);
            auto ans = getsum(j) - getsum(i - 1);
            std::cout << ans << '\n';
        }
        else
        {
            ll i, k;
            std::cin >> i >> k;
            add(i, k - arr[i]);
            arr[i] = k;
        }
    }
}