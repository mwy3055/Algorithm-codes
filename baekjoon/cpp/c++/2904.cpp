#include <bits/stdc++.h>

using vi = std::vector<int>;
using umap = std::unordered_map<int, int>;

int n;
vi numbers, primes;
std::vector<umap> prime_factors;

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

void preprocess()
{
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i++)
    {
        bool prime = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            primes.push_back(i);
        }
    }
}

void factorize()
{
    for (auto num : numbers)
    {
        umap factor;
        for (auto &prime : primes)
        {
            int count = 0;
            while (num % prime == 0)
            {
                num /= prime;
                count++;
            }
            if (count != 0)
                factor[prime] = count;
        }
        prime_factors.push_back(factor);
    }
}

// p^x
long long pow(int p, int x)
{
    long long rtn = 1;
    for (int i = 0; i < x; i++)
        rtn *= p;
    return rtn;
}

void solve()
{
    preprocess();
    factorize();

    // 일단 몇 개씩 가지고 있는지 확인
    umap factor_sums;
    for (auto &factor : prime_factors)
    {
        for (auto &[prime, count] : factor)
        {
            factor_sums[prime] += count;
        }
    }

    // 정답: 모든 소인수를 분배한 값
    long long ans = 1;
    umap factor_ans;
    for (auto &[prime, count] : factor_sums)
    {
        if (count / n > 0)
        {
            factor_ans[prime] = count / n;
            ans *= pow(prime, count / n);
        }
    }

    // 어느 소인수가 몇 개 부족한가?
    std::vector<umap> insufficient;
    for (auto &prime_factor : prime_factors)
    {
        umap insuff;
        for (auto &[prime, need] : factor_ans)
        {
            if (prime_factor[prime] < need)
            {
                insuff[prime] = need - prime_factor[prime];
            }
        }
        insufficient.push_back(insuff);
    }

    // 부족한 만큼 가져와야: 이동 count
    int count = 0;
    for (int i = 0; i < prime_factors.size(); i++)
    {
        for (auto &[prime, need] : factor_ans)
        {
            if (prime_factors[i][prime] < need)
                count += insufficient[i][prime];
        }
    }
    std::cout << ans << ' ' << count << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}