#include <bits/stdc++.h>

using ll = long long;

const int MAX = 1000000;
bool prime[MAX + 1];
std::vector<int> primes;

void calculate()
{
    std::memset(prime, true, MAX + 1);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= MAX; i++)
    {
        if (prime[i])
        {
            primes.push_back(i);
            for (ll p = i * i; p <= MAX; p += i)
            {
                prime[p] = false;
            }
        }
    }
}

bool isprime(ll n)
{
    for (auto &p : primes)
    {
        if (n % p == 0)
            return false;
    }
    return true;
}

ll solve(ll n)
{
    if (n == 1)
        return 1;
    else if (isprime(n))
        return n - 1;

    // n의 각 소인수가 몇 번 곱해졌는지 세어야 한다.
    std::vector<int> counts;
    for (auto &p : primes)
    {
        int count = 0;
        while (n % p == 0)
        {
            n /= p;
            count++;
        }
        if (count)
            counts.push_back(count);
    }
    if (n == 1)
        counts.push_back(1);

    ll count_factor = 1;
    for (auto &c : counts)
        count_factor *= (c + 1);
    return n - count_factor;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    calculate();

    ll n;
    std::cin >> n;
    std::cout << solve(n) << '\n';
}