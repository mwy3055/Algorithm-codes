#include <bits/stdc++.h>

using ll = long long;

struct island
{
    bool sheep;
    ll count; // 양 또는 늑대의 수, 다리
    island(bool sheep, ll count) : sheep(sheep), count(count) {}
};

int n;
std::vector<island> islands;
std::vector<int> graph[123456]; // graph[i]: i와 연결된 섬
std::vector<bool> visit(123456, false);

void getinput()
{
    std::cin >> n;
    islands.emplace_back(false, 0);
    for (int i = 1; i < n; i++)
    {
        char t;
        ll a, p;
        std::cin >> t >> a >> p;
        islands.emplace_back(t == 'S', a);
        p--;
        graph[i].push_back(p);
        graph[p].push_back(i);
    }
}

ll search(int cur)
{
    visit[cur] = true;
    ll sheep_sum = 0;
    for (auto &adj : graph[cur])
    {
        if (!visit[adj])
        {
            sheep_sum += search(adj);
        }
    }
    if (islands[cur].sheep)
    {
        return islands[cur].count + sheep_sum;
    }
    else
    {
        return std::max(0LL, sheep_sum - islands[cur].count);
    }
}

ll solve()
{
    visit[0] = true;
    return search(0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}