#include <bits/stdc++.h>

using ll = long long;
using pll = std::pair<ll, ll>; // 난이도, 몬스터

int n, m;
ll difficulty[100001];
std::vector<pll> tips[100001];
bool killed[100001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> difficulty[i];
    int p;
    std::cin >> p;
    for (int i = 0; i < p; i++)
    {
        int a, b, t;
        std::cin >> a >> b >> t;
        tips[a].emplace_back(t, b);
        difficulty[b] += t;
    }
}

// 난이도가 제일 낮은 몬스터를 먼저 잡자.
ll solve()
{
    std::priority_queue<pll, std::vector<pll>, std::greater<pll>> pq;

    for (int i = 1; i <= n; i++)
    {
        pq.emplace(difficulty[i], i);
    }

    int count = 0;
    ll ans = 0;
    while (count < m)
    {
        auto [diff, monster] = pq.top();
        pq.pop();

        if (killed[monster])
            continue;
        killed[monster] = true;
        count++;
        ans = std::max(ans, diff);
        for (auto &[d, child] : tips[monster])
        {
            // 이미 죽인 몬스터는 생략
            if (!killed[child])
            {
                // 난이도가 여러 번 낮아질 수 있으므로..
                difficulty[child] -= d;
                pq.emplace(difficulty[child], child);
            }
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}