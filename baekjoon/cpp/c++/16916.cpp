#include <bits/stdc++.h>

int pi[1000000]; // length of pattern
void getpi(std::string &p)
{
    // pi[0] = 0
    int j = 0;
    for (int i = 1; i < p.size(); i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
}
int kmp(std::string &t, std::string &p)
{
    int j = 0, tlen = t.size(), plen = p.size();
    for (int i = 0; i < tlen; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        if (t[i] == p[j])
        {
            if (j == plen - 1)
            {
                return 1;
            }
            else
            {
                j++;
            }
        }
    }
    return 0;
}

int solve(std::string &s, std::string &p)
{
    if (s.length() < p.length())
        return 0;
    else if (s == p)
        return 1;

    getpi(s);
    return kmp(s, p);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string s, p;
    std::cin >> s >> p;
    std::cout << solve(s, p) << '\n';
}