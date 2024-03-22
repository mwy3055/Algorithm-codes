#include <bits/stdc++.h>

int n, k;
int t[10][10], mint[10][10];
const int MAX = 0x3f3f3f3f;

using node = std::pair<int, int>; // dist, cur

void getinput()
{
    std::cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> t[i][j];
        }
    }
}

void dijk(int start)
{
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;

    mint[start][start] = 0;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [dist, cur] = pq.top();
        pq.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == cur)
                continue;

            if (mint[start][i] > dist + t[cur][i])
            {
                mint[start][i] = dist + t[cur][i];
                pq.emplace(mint[start][i], i);
            }
        }
    }
}

void preprocess()
{
    std::memset(mint, 0x3f, sizeof(mint));

    for (int i = 0; i < n; i++)
        dijk(i);
}

int get_dist(std::vector<int> &order)
{
    int d = 0;
    for (int i = 0; i < n - 1; i++)
    {
        d += mint[order[i]][order[i + 1]];
    }
    return d;
}

int solve()
{
    preprocess();

    std::vector<int> order;
    order.push_back(k);
    for (int i = 0; i < n; i++)
    {
        if (i == k)
            continue;
        order.push_back(i);
    }

    int ans = MAX;
    do
    {
        int tans = get_dist(order);
        ans = std::min(ans, tans);
    } while (std::next_permutation(order.begin() + 1, order.end()));

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}