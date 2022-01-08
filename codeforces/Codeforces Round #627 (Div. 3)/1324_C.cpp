#include <bits/stdc++.h>
using namespace std;

bool bfs(string &str, int d)
{
    int len = str.length();
    set<int> s;
    for (int i = 0; i <= len; i++)
        s.insert(i);
    queue<int> q;

    q.push(-1);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if (top == len)
            return true;

        set<int>::iterator left, right;
        if (top == -1 || str[top] == 'R')
        {
            int lbound = top + 1, rbound = min(len, top + d);
            left = s.lower_bound(lbound), right = s.upper_bound(rbound);
        }
        else
        {
            int lbound = max(0, top - d), rbound = top - 1;
            left = s.lower_bound(lbound), right = s.upper_bound(top);
        }

        vector<set<int>::iterator> erase_list;
        for (auto it = left; it != right; it++)
        {
            if (s.count(*it))
            {
                q.push(*it);
                erase_list.push_back(it);
            }
        }
        for (auto &er : erase_list)
            s.erase(er);
    }
    return false;
}
int solve(string &s)
{
    int l = 1, r = s.length() + 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (bfs(s, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
}