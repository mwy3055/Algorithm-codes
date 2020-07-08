#include <bits/stdc++.h>

using pii = std::pair<int, int>;
std::string s;
std::vector<std::string> ans;

void remove(std::vector<pii> &brackets, std::vector<bool> &select)
{
    bool no_remove = true;
    std::vector<int> rmidx;
    for (int i = 0; i < select.size(); i++)
    {
        if (select[i])
        {
            no_remove = false;
            rmidx.push_back(brackets[i].first);
            rmidx.push_back(brackets[i].second);
        }
    }
    if (no_remove)
        return;

    sort(rmidx.begin(), rmidx.end(), std::greater<int>());
    std::string removed = s;
    for (auto &i : rmidx)
    {
        removed.erase(removed.begin() + i);
    }
    ans.push_back(removed);
}

void dfs(int dep, std::vector<pii> &brackets, std::vector<bool> &select)
{
    if (dep == brackets.size())
    {
        // remove
        remove(brackets, select);
        return;
    }

    select[dep] = true;
    dfs(dep + 1, brackets, select);
    select[dep] = false;
    dfs(dep + 1, brackets, select);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> s;

    std::stack<int> st;
    std::vector<pii> brackets;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            int begin = st.top();
            st.pop();
            brackets.emplace_back(begin, i);
        }
    }

    std::vector<bool> select(brackets.size(), false);
    dfs(0, brackets, select);

    sort(ans.begin(), ans.end());
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end()); // remove duplicate
    for (auto &a : ans)
        std::cout << a << '\n';
}