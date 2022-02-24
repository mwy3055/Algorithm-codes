#include <bits/stdc++.h>

using staff = std::pair<std::string, int>;
using entry = std::pair<double, int>; // value, index

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int x, n;
    std::cin >> x >> n;
    std::vector<staff> staffs;
    for (int i = 0; i < n; i++)
    {
        staff s;
        std::cin >> s.first >> s.second;
        if (s.second * 20 >= x)
            staffs.push_back(s);
    }

    int size = staffs.size();
    std::vector<entry> entries;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            entries.emplace_back((double)staffs[i].second / j, i);
        }
    }
    std::sort(entries.begin(), entries.end(), std::greater<entry>());

    std::vector<staff> chips(size);
    for (int i = 0; i < size; i++)
    {
        chips[i] = staffs[i];
        chips[i].second = 0;
    }
    for (int j = 0; j < 14; j++)
    {
        chips[entries[j].second].second++;
    }
    std::sort(chips.begin(), chips.end());
    for (auto &c : chips)
        std::cout << c.first << ' ' << c.second << '\n';
}