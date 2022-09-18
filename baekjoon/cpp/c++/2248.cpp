#include <bits/stdc++.h>

using ll = long long;

// n자리의 이진수 중에서 1인 비트가 k개인 수의 개수
ll memoi[32][32];

ll dp(int n, int k)
{
    if (n < 0 || k < 0)
        return 0;
    auto &ret = memoi[n][k];
    if (n == 1)
        ret = (k == 1);
    if (k == 0)
        ret = 1;
    if (ret != -1)
        return ret;
    // 1로 시작하는 경우, 0으로 시작하는 경우
    ret = dp(n - 1, k - 1) + dp(n - 1, k);
    return ret;
}

ll sum(int n, int k)
{
    ll result = 0;
    for (int i = 0; i <= k; i++)
        result += dp(n, i);
    return result;
}

std::string solve(ll n, ll l, ll i)
{
    // 이진수가 1로 시작해야 하는가? 0으로 시작해야 하는가?
    std::string ans;
    // 자릿수
    for (int cur = n; cur > 0; cur--)
    {
        auto if_starts_0 = sum(cur - 1, l);
        if (i <= if_starts_0)
        {
            ans.push_back('0');
        }
        else
        {
            ans.push_back('1');
            i -= if_starts_0;
            l--;
        }
    }
    return ans;
}

void init()
{
    std::memset(memoi, -1, sizeof(memoi));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();

    ll n, l, i;
    std::cin >> n >> l >> i;
    std::cout << solve(n, l, i) << '\n';
}