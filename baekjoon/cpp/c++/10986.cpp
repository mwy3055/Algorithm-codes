#include <bits/stdc++.h>

using ll = long long;

const int MAX = 1000000;
int n, m, a[MAX + 1];
ll subsum[MAX + 1], count[MAX + 1];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
}

void preprocess()
{
    count[0]++;
    for (int i = 1; i <= n; i++)
    {
        subsum[i] = subsum[i - 1] + a[i];
        count[subsum[i] % m]++;
    }
}

int get_sub(int i, int j)
{
    return subsum[j] - subsum[i - 1];
}

ll comb(ll num)
{
    return (num * (num - 1)) / 2;
}

ll solve()
{
    // 나머지가 같은 인덱스 두 개를 선택하자.
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (count[i] >= 2)
        {
            ans += comb(count[i]);
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    preprocess();
    std::cout << solve() << '\n';
}