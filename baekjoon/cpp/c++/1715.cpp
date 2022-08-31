#include <bits/stdc++.h>

using ll = long long;

int n;
std::vector<int> numbers;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }
}

ll solve()
{
    if (n == 1)
        return 0;

    ll ans = 0;
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;

    for (auto &num : numbers)
        pq.push(num);

    while (pq.size() > 1)
    {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}