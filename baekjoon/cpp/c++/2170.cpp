#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n;
std::vector<pii> points;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        points.emplace_back(x, y);
    }
}

int solve()
{
    // O(N)
    std::vector<int> coords;
    for (auto &[x, y] : points)
    {
        coords.push_back(x);
        coords.push_back(y);
    }
    // O(NlogN)
    std::sort(coords.begin(), coords.end());
    auto it = std::unique(coords.begin(), coords.end());

    int zip_coord_size = coords.size();
    std::vector<int> start(zip_coord_size, 0), finish(zip_coord_size, 0);
    for (auto &[x, y] : points)
    {
        auto xp = std::lower_bound(coords.begin(), it, x);
        auto yp = std::lower_bound(coords.begin(), it, y);
        start[xp - coords.begin()]++;
        finish[yp - coords.begin()]++;
    }

    // O(N)
    int ans = 0, count = start[0];
    for (int i = 1; i < zip_coord_size; i++)
    {
        if (count > 0)
        {
            ans += coords[i] - coords[i - 1];
        }
        count = count + start[i] - finish[i];
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