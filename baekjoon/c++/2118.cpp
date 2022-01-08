#include <bits/stdc++.h>

// edge[i]: dist between i and (i + 1) mod n
// dist_clock[i]: clockwise distance between i and (i + 1)
int edge[50001], dist_clock[50001], dist_ccw[50001];

void preprocess(int n)
{
    for (int i = 2; i <= n; i++)
        dist_clock[i] = dist_clock[i - 1] + edge[i - 1];
    for (int i = n; i > 1; i--)
        dist_ccw[i] = dist_ccw[(i % n) + 1] + edge[i];
}

int getdist(int i, int j)
{
    int d1 = dist_clock[j] - dist_clock[i];
    int d2 = dist_clock[i] + dist_ccw[j];
    return std::min(d1, d2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> edge[i];
    preprocess(n);

    for (int i = 1; i <= n; i++)
        std::cout << dist_clock[i] << ' ';
    std::cout << '\n';
    for (int i = 1; i <= n; i++)
        std::cout << dist_ccw[i] << ' ';
    std::cout << '\n';

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int d = getdist(i, j);
            std::cout << "dist from " << i << " to " << j << ": " << d << '\n';
            ans = std::max(ans, d);
        }
    }
    std::cout << ans;
}