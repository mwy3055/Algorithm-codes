#include <bits/stdc++.h>

using pii = std::pair<int, int>;
using vi = std::vector<int>;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, h;
    std::cin >> n >> h;
    vi seok, jong; // 석순, 종유석
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> len;
        if (i % 2 == 0)
            seok.push_back(len);
        else
            jong.push_back(len);
    }

    std::sort(seok.begin(), seok.end());
    std::sort(jong.begin(), jong.end());

    std::vector<pii> pairs;
    for (int i = 1; i <= h; i++)
    {
        int break1 = seok.end() - std::lower_bound(seok.begin(), seok.end(), i);
        int break2 = jong.end() - std::lower_bound(jong.begin(), jong.end(), h - i + 1);
        pairs.emplace_back(break1 + break2, i);
    }
    std::sort(pairs.begin(), pairs.end());

    int ans = pairs.front().first, cnt = 0;
    while (pairs[cnt].first == ans)
        cnt++;
    std::cout << ans << ' ' << cnt;
}