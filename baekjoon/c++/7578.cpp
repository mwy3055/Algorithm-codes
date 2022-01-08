#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;
std::vector<pii> pairs;
int n, order[1000001][2];

const int SIZE = (1 << 20);
int BIT[SIZE];
int getsum(ll i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += BIT[i];
        i -= i & -i;
    }
    return sum;
}
void add(ll i, ll val)
{
    while (i < SIZE)
    {
        BIT[i] += val;
        i += i & -i;
    }
}

ll solve(int &n, std::vector<int> &arr)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += i - getsum(arr[i]);
        add(arr[i], 1);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        std::cin >> num;
        order[num][0] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int num;
        std::cin >> num;
        order[num][1] = i;
    }

    for (int i = 0; i <= 1000000; i++)
    {
        if (order[i][0] != 0)
        {
            pairs.emplace_back(order[i][0], order[i][1]);
        }
    }
    std::sort(pairs.begin(), pairs.end());

    std::vector<int> test;
    for (auto &p : pairs)
        test.push_back(p.second);
    std::cout << solve(n, test);
}