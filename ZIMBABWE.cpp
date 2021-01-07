#include <bits/stdc++.h>

using ll = long long;
const int MOD = 1000000007;

int dp[1 << 14][20][2];

std::string e, digits;
int n, m;

// index: 이번에 채울 자릿수
// taken: 지금까지 사용된 자릿수의 bitmask
// mod: 지금까지 만든 가격의 나머지
// less: 현재까지 만든 가격이 e보다 작은가? 혹은 작지 않을 수 있는가?
int search(int index, int taken, int mod, bool less)
{
    auto &ret = dp[taken][mod][less];
    if (ret != -1)
        return ret;
    if (index == n)
        return ret = (less && (mod == 0));

    ret = 0;
    for (int nidx = 0; nidx < n; nidx++) // nidx번 자릿수를 사용해 볼까?
    {
        if ((taken & (1 << nidx)) == 0)
        {
            // e보다 작은 가격만을 만들어야 함
            if (!less && e[index] < digits[nidx])
                continue;
            // 같은 숫자는 한번만 선택해야 함 ex) 224를 두 번 세는 경우
            if (nidx > 0 && digits[nidx - 1] == digits[nidx] && (taken & (1 << (nidx - 1))) == 0)
                continue;
            auto n_taken = taken | (1 << nidx);
            auto n_mod = (mod * 10 + (digits[nidx] - '0')) % m;
            auto n_less = less || (e[index] > digits[nidx]);
            ret = (ret + search(index + 1, n_taken, n_mod, n_less)) % MOD;
        }
    }
    return ret;
}

int solve(std::string &e, int &m)
{
    memset(dp, -1, sizeof(dp));
    digits = e;
    std::sort(digits.begin(), digits.end());
    n = e.size();
    return search(0, 0, 0, false);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        std::cin >> e >> m;
        std::cout << solve(e, m) << '\n';
    }
}