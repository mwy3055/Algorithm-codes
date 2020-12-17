#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;
int d[101][101];
int via[101][101];

void floyd_warshall(int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && j != k && k != i)
                {
                    int &old_d = d[i][j], new_d = d[i][k] + d[k][j];
                    if (old_d > new_d)
                    {
                        old_d = new_d;
                        via[i][j] = k;
                    }
                }
            }
        }
    }
}

std::deque<int> get_mid(int from, int to)
{
    std::deque<int> result;
    auto &adj = via[from][to];
    if (adj == -1)
        return result;

    auto left = get_mid(from, adj);
    for (auto &l : left)
        result.push_back(l);

    result.push_back(adj);

    auto right = get_mid(adj, to);
    for (auto &r : right)
        result.push_back(r);
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(d, 0x3f, sizeof(d));
    memset(via, -1, sizeof(via));

    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        d[a][b] = std::min(d[a][b], c);
    }

    floyd_warshall(n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cout << (d[i][j] == INF ? 0 : d[i][j]) << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                std::cout << 0 << '\n';
            }
            else
            {
                auto result = get_mid(i, j);
                result.push_front(i);
                result.push_back(j);
                std::cout << result.size() << ' ';
                for (auto &r : result)
                    std::cout << r << ' ';
                std::cout << '\n';
            }
        }
    }
}