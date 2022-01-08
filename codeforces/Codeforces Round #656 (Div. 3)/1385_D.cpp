#include <bits/stdc++.h>

using sit = std::string::iterator;

int count(char c, sit begin, sit end)
{
    int rtn = 0;
    for (auto it = begin; it != end; it++)
    {
        if (*it == c)
            rtn++;
    }
    return rtn;
}

int getmin(char c, sit begin, sit end)
{
    if (begin + 1 == end)
        return *begin != c;
    int half = (end - begin) / 2;
    int val1 = (half - count(c, begin, begin + half)) + getmin(c + 1, begin + half, end);
    int val2 = getmin(c + 1, begin, begin + half) + (half - count(c, begin + half, end));
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