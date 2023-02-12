#include <bits/stdc++.h>

void push(std::string &s, bool ends_with_k, int len)
{
    s.push_back(ends_with_k ? '5' : '1');
    for (int i = 0; i < len - 1; i++)
    {
        s.push_back('0');
    }
}

std::string solve_max(std::string &s)
{
    std::string ans;

    int last_pos = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'K')
        {
            auto len = i - last_pos; // K로 끝나는 문자열의 길이
            push(ans, true, len);
            last_pos = i;
        }
        else if (i == s.length() - 1)
        {
            auto len = i - last_pos;
            for (int j = 0; j < len; j++)
            {
                ans.push_back('1');
            }
        }
    }
    return ans;
}

std::string solve_min(std::string &s)
{
    std::string ans;
    // M은 최대한 길게
    // K는 끊어서
    for (int i = 0; i < s.length();)
    {
        if (s[i] == 'K')
        {
            ans.push_back('5');
            i++;
        }
        else
        {
            auto next = i;
            while (next + 1 < s.length() && s[next + 1] == 'M')
                next++;
            auto len = next - i + 1;
            push(ans, false, len);
            i = next + 1;
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s;
    std::cin >> s;

    std::cout << solve_max(s) << '\n'
              << solve_min(s) << '\n';
}