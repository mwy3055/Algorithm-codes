#include <bits/stdc++.h>

using ll = long long;

ll mylog2(ll i)
{
    ll log = 0;
    do
    {
        log++;
        i /= 2;
    } while (i);
    return log - 1;
}

// b보다 작거나 같으면서 가장 큰 n의 배수
ll upper(ll b, ll n)
{
    if (b % n == 0)
        return b;
    return n * (b / n);
}

ll solve(ll, ll);

// sum(f(i)) for 1 <= i <= n
ll calc(ll n)
{
    if (n <= 0)
        return 0;
    ll log = mylog2(n), rtn = 0;
    for (ll i = 0; i <= log; i++)
    {
        ll sq = 1LL << i;
        // 구간별
        ll len = sq, right_bound = upper(n, sq); // 구간의 길이와 끝 (exclusive)
        ll seg_count = right_bound / len;
        ll one_count = seg_count / 2;
        rtn += one_count * len;
        // 자투리
        rtn += ((n & sq) != 0) * (n - right_bound + 1);
    }
    return rtn;
}

ll solve(ll a, ll b)
{
    return calc(b) - calc(a - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll a, b;
    std::cin >> a >> b;
    std::cout << solve(a, b) << '\n';
}