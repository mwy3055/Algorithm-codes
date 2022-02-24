#include <bits/stdc++.h>

int n, q, m, par[300001];
std::vector<int> children[300001];
std::vector<int> results;
std::vector<std::pair<int, int>> merges;

void getinput()
{
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> par[i];
        if (i != par[i])
        {
            children[par[i]].push_back(i);
        }
    }
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int result;
        std::cin >> result;
        results.push_back(result);
    }
}

void make_tree(int cur)
{
    for (auto &child : children[cur])
    {
        make_tree(child);
        merges.emplace_back(child, cur);
    }
}

void make_query()
{
    for (int i = 1; i <= n; i++)
    {
        if (i == par[i])
        {
            make_tree(i);
        }
    }
    // 무의미한 1번 쿼리를 출력한 후
    auto left = (q - m) - merges.size();
    for (int i = 0; i < left; i++)
    {
        std::cout << "1 1 1" << '\n';
    }
    // 진짜 1번 쿼리 출력
    for (auto &[u, v] : merges)
        std::cout << 1 << ' ' << u << ' ' << v << '\n';
}

void solve()
{
    std::cout << n << ' ' << q << '\n';
    // 2번 질의 먼저 출력
    for (auto &result : results)
        std::cout << 2 << ' ' << result << '\n';
    // 1번 질의 (Q - M)개 출력
    make_query();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}