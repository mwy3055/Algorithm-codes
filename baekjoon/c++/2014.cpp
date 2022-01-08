#include <bits/stdc++.h>

using ll = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::vector<int> primes;
    std::cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        int p;
        std::cin >> p;
        primes.push_back(p);
    }
    std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
    for (auto &p : primes)
        pq.push(p);

    // pop n times
    long long head;
    for (int i = 0; i < n; i++)
    {
        head = pq.top();
        pq.pop();
        for (auto &prime : primes)
        {
            pq.push(head * prime);
            if (head % prime == 0)
                break;
        }
    }
    std::cout << head << '\n';
}