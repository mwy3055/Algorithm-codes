#include <bits/stdc++.h>

struct ratio
{
    int a, b, p, q;
    ratio(int a, int b, int p, int q) : a(a), b(b), p(p), q(q) {}
};

using ll = long long;

ll GCD(ll a, ll b)
{
    //constraint: a <= b
    if (a > b)
    {
        std::swap(a, b);
    }
    if (b % a)
        return GCD(a, b % a);
    else
        return a;
}

// why RTE?
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<ratio> ratios;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, p, q;
        std::cin >> a >> b >> p >> q;
        int gcd = GCD(p, q);
        ratios.emplace_back(a, b, p / gcd, q / gcd);
    }

    std::set<int> sets[n];
    ll amounts[n];
    for (int i = 0; i < n; i++)
    {
        amounts[i] = 1;
        sets[i].insert(i);
    }
    for (auto &r : ratios)
    {
        ll base = amounts[r.a] * amounts[r.b];
        ll newa = base * r.p, newb = base * r.q;
        auto coefA = newa / amounts[r.a], coefB = newb / amounts[r.b];
        // connected with a
        for (auto &i : sets[r.a])
            amounts[i] *= coefA;
        // connected with b
        for (auto &i : sets[r.b])
            amounts[i] *= coefB;

        auto backup = sets[r.a];
        backup.merge(sets[r.b]);
        for (auto &i : backup)
            sets[i] = backup;
    }

    auto gcd = amounts[0];
    for (int i = 1; i < n; i++)
        gcd = GCD(gcd, amounts[i]);
    for (int i = 0; i < n; i++)
        amounts[i] /= gcd;

    for (int i = 0; i < n; i++)
        std::cout << amounts[i] << ' ';
}