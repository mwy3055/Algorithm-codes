#include <bits/stdc++.h>

bool solve(std::string &s, std::string &t)
{
    std::queue<std::string> q;
    q.push(t);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        if (top == s)
            return true;
        if (top.empty())
            continue;
        if (top.back() == 'A')
        {
            q.push(top.substr(0, top.size() - 1));
        }
        if (top.front() == 'B')
        {
            auto sub = top.substr(1);
            std::reverse(sub.begin(), sub.end());
            q.push(sub);
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s, t;
    std::cin >> s >> t;
    std::cout << solve(s, t) << '\n';
}