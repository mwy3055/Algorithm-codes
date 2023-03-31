#include <bits/stdc++.h>

using edge = std::pair<int, int>;
using ll = long long;

int n, m;
std::vector<edge> edges;
bool conn[2001][2001];
ll subsum[2001][2001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        edges.emplace_back(a, b);
        conn[a][b] = true;
    }
}

void calculate_subsum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            subsum[i][j] = subsum[i - 1][j] + subsum[i][j - 1] - subsum[i - 1][j - 1] + conn[i][j];
        }
    }
}

ll get_subsum(int i1, int j1, int i2, int j2)
{
    return subsum[i2][j2] - subsum[i1 - 1][j2] - subsum[i2][j1 - 1] + subsum[i1 - 1][j1 - 1];
}

ll solve()
{
    calculate_subsum();

    // (i, j)랑 교차하는 간선
    // a < i and edges[a] > j인 간선만 세면 된다.

    // 간선 (i, j)에 대해 [1, i] * [j+1, n] 구간의 수를 구하면 된다.
    ll ans = 0;
    for (auto &[i, j] : edges)
    {
        auto temp = get_subsum(1, j + 1, i - 1, n);
        ans += temp;
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