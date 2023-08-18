#include <bits/stdc++.h>

void solve(std::string &s)
{
    bool palin = true;
    int count = 0;

    int l = 0, r = s.size() - 1;
    do
    {
        count++;
        if (l >= r)
            break;
        if (s[l] != s[r])
        {
            palin = false;
            break;
        }
        l++, r--;
    } while (true);
    std::cout << palin << ' ' << count << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        std::string s;
        std::cin >> s;
        solve(s);
    }
}