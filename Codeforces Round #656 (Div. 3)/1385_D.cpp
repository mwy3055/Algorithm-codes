#include <bits/stdc++.h>

using sit = std::string::iterator;

bool isgood(char c, sit begin, sit end)
{
    if (begin + 1 == end)
        return true;
    int len = end - begin;
    if (isgood(c, begin, begin + len / 2) && isgood(c + 1, begin + len / 2, end))
        return true;
    else if (isgood(c + 1, begin, begin + len / 2) && isgood(c, begin + len / 2, end))
        return true;
    return false;
}

int getmin(char c, sit begin, sit end)
{
    if (begin + 1 == end)
        return *begin != c;
    if (isgood(c, begin, end))
        return 0;
    int len = end - begin;
    int val1 = getmin(c, begin, begin + len / 2) + getmin(c + 1, begin + len / 2, end);
    int val2 = getmin(c + 1, begin, begin + len / 2) + getmin(c, begin + len / 2, end);
    return std::min(val1, val2);
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
        std::string s;
        std::cin >> n >> s;
        std::cout << getmin('a', s.begin(), s.end()) << '\n';
    }
}