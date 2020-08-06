#include <bits/stdc++.h>

void solve(int &n, std::string &s, int &ans, std::vector<int> &a)
{
    std::queue<int> zeroidx, oneidx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeroidx.push(i);
        else
            oneidx.push(i);
    }

    while (!zeroidx.empty() || !oneidx.empty())
    {
        if (zeroidx.empty())
        {
            while (!oneidx.empty())
            {
                a[oneidx.front()] = ++ans;
                oneidx.pop();
            }
            return;
        }
        else if (oneidx.empty())
        {
            while (!zeroidx.empty())
            {
                a[zeroidx.front()] = ++ans;
                zeroidx.pop();
            }
            return;
        }
        if (zeroidx.front() < oneidx.front())
        {
            // 010101
            int before = zeroidx.front();
            zeroidx.pop();
            a[before] = ++ans;
            for (int i = 1; !zeroidx.empty() || !oneidx.empty(); i++)
            {
                if (i % 2)
                {
                    if (oneidx.front() < before || oneidx.empty())
                        break;
                    before = oneidx.front();
                    oneidx.pop();
                    a[before] = ans;
                }
                else
                {
                    if (zeroidx.front() < before || zeroidx.empty())
                        break;
                    before = zeroidx.front();
                    zeroidx.pop();
                    a[before] = ans;
                }
            }
        }
        else
        {
            int before = oneidx.front();
            oneidx.pop();
            a[before] = ++ans;
            for (int i = 1; !zeroidx.empty() || !oneidx.empty(); i++)
            {
                if (i % 2)
                {
                    if (zeroidx.front() < before || zeroidx.empty())
                        break;
                    before = zeroidx.front();
                    zeroidx.pop();
                    a[before] = ans;
                }
                else
                {
                    if (oneidx.front() < before || oneidx.empty())
                        break;
                    before = oneidx.front();
                    oneidx.pop();
                    a[before] = ans;
                }
            }
        }
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
        int n;
        std::cin >> n;
        std::string s;
        std::cin >> s;
        int ans = 0;
        std::vector<int> a(n);

        solve(n, s, ans, a);
        std::cout << ans << '\n';
        for (auto &ai : a)
            std::cout << ai << ' ';
        std::cout << '\n';
    }
}