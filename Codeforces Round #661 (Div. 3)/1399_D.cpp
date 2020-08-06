#include <bits/stdc++.h>

void pop(std::deque<int> &first, std::deque<int> &second, std::vector<int> &a, int &ans)
{
    int before = first.front();
    first.pop_front();
    a[before] = ++ans;
    for (int i = 1; !first.empty() || !second.empty(); i++)
    {
        if (i % 2)
        {
            auto it = std::upper_bound(second.begin(), second.end(), before);
            if (it == second.end())
                break;
            before = *it;
            a[before] = ans;
            second.erase(it);
        }
        else
        {
            auto it = std::upper_bound(first.begin(), first.end(), before);
            if (it == first.end())
                break;
            before = *it;
            a[before] = ans;
            first.erase(it);
        }
    }
}

void solve(int &n, std::string &s, int &ans, std::vector<int> &a)
{
    std::deque<int> zeroidx, oneidx;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeroidx.push_back(i);
        else
            oneidx.push_back(i);
    }

    while (!zeroidx.empty() || !oneidx.empty())
    {
        if (zeroidx.empty())
        {
            while (!oneidx.empty())
            {
                a[oneidx.front()] = ++ans;
                oneidx.pop_front();
            }
            return;
        }
        else if (oneidx.empty())
        {
            while (!zeroidx.empty())
            {
                a[zeroidx.front()] = ++ans;
                zeroidx.pop_front();
            }
            return;
        }
        if (zeroidx.front() < oneidx.front())
        {
            // 010101
            pop(zeroidx, oneidx, a, ans);
        }
        else
        {
            pop(oneidx, zeroidx, a, ans);
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