#include <bits/stdc++.h>

using ll = long long;
std::vector<ll> fibo, fibo_sum;

void fibonacci()
{
    fibo.push_back(0);
    fibo.push_back(1);
    for (int i = 2; i <= 90; i++)
    {
        fibo.push_back(fibo[i - 1] + fibo[i - 2]);
    }

    fibo_sum.push_back(0);
    for (int i = 1; i <= 90; i++)
    {
        fibo_sum.push_back(fibo_sum[i - 1] + fibo[i]);
    }
}

ll if_zero(int len)
{
    // 길이 len 남은 상황에서 1을 붙이면?
    if (len == 1)
        return 1;
    else
        return fibo[len + 1];
}

ll if_one(int len)
{
    return fibo[len];
}

void solve(ll k)
{
    // 길이가 i인 이친수는 fibo[i]개.
    if (k == 1)
    {
        std::cout << "1" << '\n';
        return;
    }
    ll len = std::lower_bound(fibo_sum.begin(), fibo_sum.end(), k) - fibo_sum.begin();
    ll nth = k - fibo_sum[len - 1];
    ll last = 0;
    std::cout << "10";
    for (int cur_len = 3; cur_len <= len; cur_len++)
    {
        ll zero = if_zero(len - cur_len + 1), one = fibo[len - cur_len + 1];
        if (last == 0)
        {
            if (nth <= zero)
            {
                std::cout << "0";
                last = 0;
            }
            else
            {
                std::cout << "1";
                last = 1;
                nth -= zero;
            }
        }
        else
        {
            std::cout << "0";
            last = 0;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    fibonacci();

    ll k;
    std::cin >> k;
    solve(k);
}