#include <bits/stdc++.h>

struct segment
{
    int l, r;
    segment(int l, int r) : l(l), r(r) {}
};

bool nogap(std::vector<int> &shelf)
{
    std::vector<int> indices;
    for (int i = 0; i < shelf.size(); i++)
    {
        if (shelf[i] == 1)
            indices.push_back(i);
    }
    for (int i = 0; i < indices.size() - 1; i++)
    {
        if (indices[i] + 1 != indices[i + 1])
            return false;
    }
    return true;
}

int dist(segment a, segment b)
{
    return std::min(std::abs(a.l - b.r), std::abs(a.r - b.l)) - 1;
}

int solve(int n, std::vector<int> &shelf)
{
    if (nogap(shelf))
        return 0;
    std::vector<segment> segments;
    int cur = 0;
    while (cur < n)
    {
        if (shelf[cur] == 0)
            cur++;
        else
        {
            int next = cur;
            while (next < n && shelf[next] == 1)
                next++;
            segments.emplace_back(cur, next - 1);
            cur = next;
        }
    }

    int ans = 0;
    for (int i = 0; i < segments.size() - 1; i++)
    {
        ans += dist(segments[i], segments[i + 1]);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> shelf(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> shelf[i];
        }
        std::cout << solve(n, shelf) << '\n';
    }
}