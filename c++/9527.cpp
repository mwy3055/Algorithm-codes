#include <bits/stdc++.h>

using ll = long long;
const ll MAX = (1LL << 61) - 1;

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

ll min(ll i)
{
    return 1LL << i;
}

ll max(ll i)
{
    return (1LL << (i + 1)) - 1;
}

// a보다 크거나 같으면서 가장 작은 n의 배수
ll lower(ll a, ll n)
{
    if (a % n == 0)
        return a;
    return n * (a / n + 1);
}

// b보다 작거나 같으면서 가장 큰 n의 배수
ll upper(ll b, ll n)
{
    if (b % n == 0)
        return b;
    return n * (b / n);
}

// 2^i ~ 2^(i+1)-1
ll sq2(ll i)
{
    if (i == 0)
        return 1;
    return i * (1LL << (i - 1)) + (1 << i);
}

ll count(ll n)
{
    int ans = 0;
    while (n)
    {
        ans += n % 2;
        n /= 2;
    }
    return ans;
}

ll naive(ll a, ll b)
{
    ll ans = 0;
    for (ll i = a; i <= b; i++)
        ans += count(i);
    return ans;
}

/**
 * a와 b를 이진수로 나타냈을 때의 공통부분을 제거할 수 있는 bitmask를 반환
 */
ll get_mask(ll a, ll b)
{
    ll sq = mylog2(a);
    while ((a & (1LL << sq)) == (b & (1LL << sq)))
    {
        sq--;
    }
    return (1LL << (sq + 1)) - 1;
}

ll solve(ll, ll);

// log2(left) = log2(right)인 left와 right만 주어짐
ll calc(ll left, ll right)
{
    if (left == right)
        return count(left);
    else if (left > right)
        return 0;
    ll log = mylog2(left), ans = 0;
    if (left == min(log) && right == max(log))
        return sq2(log);
    // 켜져 있는 i번째 비트의 개수 세기
    for (ll i = 0; i < log; i++)
    {
        ll sq = 1LL << i;
        ll left_bound = lower(left, sq), right_bound = upper(right, sq);
        if (left_bound > right || right_bound < left)
        {
            ans += ((left & sq) != 0) * (right - left + 1);
            continue;
        }
        // [left, left_bound)
        ans += ((left & sq) != 0) * (left_bound - left);
        // [left_bound, right_bound)
        ll seg_num = (right_bound - left_bound) / sq;
        ll first_count = seg_num / 2 + seg_num % 2, second_count = seg_num / 2;
        ll first_ans = ((left_bound & sq) != 0) * first_count * sq, second_ans = (((left_bound + sq) & sq) != 0) * second_count * sq;
        ans += first_ans + second_ans;
        // [right_bound, right]
        ans += ((right & sq) != 0) * (right - right_bound + 1);
    }
    // 항상 켜져 있는 최상위 비트 세기
    return ans + (right - left + 1);
}

ll solve(ll a, ll b)
{
    ll ans = 0, log_a = mylog2(a);
    ll log_max = max(log_a);
    ll left = a, right = std::min(b, log_max);
    do
    {
        right = std::min(b, log_max);
        ll tans = calc(left, right);
        ans += tans;
        assert(tans >= 0);
        log_max = (log_max << 1) + 1;
        left = right + 1;
    } while (right < b);
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll a, b;
    std::cin >> a >> b;
    std::cout << solve(a, b) << ' ' << naive(a, b) << '\n';
}