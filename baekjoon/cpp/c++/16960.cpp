#include <bits/stdc++.h>

using vi = std::vector<int>;

bool solve(int &n, int &m, std::vector<vi> &switches, vi &lamp_count)
{
    for (auto &s : switches)
        std::sort(s.begin(), s.end());

    for (int t = 0; t < n; t++) // t번 스위치를 꺼도 될까?
    {
        auto &target = switches[t];
        bool can = true;
        for (int l = 1; l <= m; l++) // t를 꺼도 l번 램프가 켜질까?
        {
            int count = lamp_count[l];
            if (std::binary_search(target.begin(), target.end(), l))
                count--;
            if (count < 1)
            {
                can = false;
                break;
            }
        }
        if (can)
            return true;
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<vi> switches(n);
    vi lamp_count(m + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt;
        std::cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int l;
            std::cin >> l;
            switches[i].push_back(l);
            lamp_count[l]++;
        }
    }

    std::cout << solve(n, m, switches, lamp_count);
}