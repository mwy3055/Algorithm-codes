#include <bits/stdc++.h>

const int MAX = 0x3f3f3f3f;
std::vector<int> count[26];

std::pair<int, int> search(int &index, int &k)
{
    auto &val = count[index];
    int minv = MAX, maxv = 0;
    for (int i = 0; i + k - 1 < val.size(); i++)
    {
        minv = std::min(minv, val[i + k - 1] - val[i]);
        maxv = std::max(maxv, val[i + k - 1] - val[i]);
    }
    return std::make_pair(minv, maxv);
}

void solve(std::string &w, int &k)
{
    for (int i = 0; i < 26; i++)
    {
        count[i].clear();
    }
    for (int i = 0; i < w.size(); i++)
    {
        count[w[i] - 'a'].push_back(i);
    }

    int ans1 = MAX, ans2 = 0;
    for (int i = 0; i < 26; i++)
    {
        auto [minv, maxv] = search(i, k);
        ans1 = std::min(ans1, minv);
        ans2 = std::max(ans2, maxv);
    }

    if (ans1 == MAX)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        // 길이 = (index의 차이) + 1
        std::cout << ans1 + 1 << ' ' << ans2 + 1 << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string w;
        int k;
        std::cin >> w >> k;
        solve(w, k);
    }
}