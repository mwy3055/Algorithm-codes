#include <bits/stdc++.h>

using qi = std::queue<int>;
std::vector<qi> vs(26, qi()), vt(26, qi());

int solve(std::string &s, std::string &t)
{
    for (int i = 0; i < s.length(); i++)
    {
        vs[s[i] - 'a'].push(i);
    }
    for (int i = 0; i < t.length(); i++)
    {
        vt[t[i] - 'a'].push(i);
    }

    int count = 0;
    while (true)
    {
        bool can_make = true;
        int last_idx = -1;
        for (auto &c : t)
        {
            auto i = c - 'a';
            bool exists = false;
            while (true)
            {
                if (vs[i].empty())
                {
                    break;
                }
                if (vs[i].front() > last_idx)
                {
                    exists = true;
                    last_idx = vs[i].front();
                    break;
                }
                vs[i].pop();
            }
            if (exists)
                vs[i].pop();
            else
            {
                can_make = false;
                break;
            }
        }
        if (can_make)
            count++;
        else
            break;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s, t;
    std::cin >> s >> t;
    std::cout << solve(s, t) << '\n';
}