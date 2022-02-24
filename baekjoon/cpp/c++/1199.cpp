#include <bits/stdc++.h>

// dest, id of edge
using pii = std::pair<int, int>;

int n;
std::vector<pii> edges[1001];
bool visit[10000001];

void search(int cur)
{
    auto &e = edges[cur];
    while (!e.empty())
    {
        while (!e.empty() && visit[e.back().second])
            e.pop_back();
        if (e.empty())
            break;

        auto [dest, id] = e.back();
        e.pop_back();
        visit[id] = true;
        search(dest);
    }
    std::cout << cur << ' ';
}

bool getinput()
{
    std::cin >> n;
    int id = 0;
    for (int i = 1; i <= n; i++)
    {
        int degree = 0;
        for (int j = 1; j <= n; j++)
        {
            int count;
            std::cin >> count;
            degree += count;
            if (i < j)
            {
                for (int k = 0; k < count; k++)
                {
                    edges[i].emplace_back(j, ++id);
                    edges[j].emplace_back(i, id);
                }
            }
        }
        if (degree % 2)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    if (getinput())
        search(1);
    else
        std::cout << -1;
}