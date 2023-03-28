#include <bits/stdc++.h>

using edge = std::pair<int, int>;
using node = std::pair<int, int>; // max_w, dest

const int MAX = 1000000;
int n, m, s, e;
std::vector<edge> edges[100001];
bool visit[100001];

void getinput()
{
    std::cin >> n >> m >> s >> e;
    for (int i = 0; i < m; i++)
    {
        int h1, h2, k;
        std::cin >> h1 >> h2 >> k;
        edges[h1].emplace_back(k, h2);
        edges[h2].emplace_back(k, h1);
    }
}

bool go(int w)
{
    std::memset(visit, false, sizeof(visit));
    std::queue<int> q;

    q.push(s);
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur == e)
            return true;

        for (auto &[limit, dest] : edges[cur])
        {
            if (!visit[dest] && limit >= w)
            {
                visit[dest] = true;
                q.push(dest);
            }
        }
    }

    return false;
}

int solve()
{
    for (int i = 1; i <= n; i++)
    {
        std::sort(edges[i].begin(), edges[i].end(), std::greater<edge>());
    }

    int l = 0, r = MAX;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (go(mid))
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}