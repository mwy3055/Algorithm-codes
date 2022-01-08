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
        if (n < p)
            break;
        else if (n == p)
            return true;
        else if (n % p == 0)
            return false;
    }
    return true;
}

std::vector<ll> get_pf(ll n)
{
    ll n_backup = n;
    std::vector<ll> prime_factors;
    for (auto &p : primes)
    {
        if (n < p)
            break;
        int count = 0;
        while (n % p == 0)
        {
            n /= p;
            count++;
        }
        if (count)
            prime_factors.push_back(p);
    }
    if (n != 1)
        prime_factors.push_back(n);
    return prime_factors;
}

ll getphi(ll n)
{
    auto pf = get_pf(n);
    ll phi = n;
    for (auto &p : pf)
    {
        phi /= p;
        phi *= (p - 1);
    }
    return phi;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    calculate();

    ll n, ans;
    std::cin >> n;

    if (n == 1)
        ans = 1;
    else if (isprime(n))
        ans = n - 1;
    else
        ans = getphi(n);
    std::cout << ans << '\n';
}