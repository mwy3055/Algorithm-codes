#include <bits/stdc++.h>

using ll = long long;

std::string solve(ll s, ll t)
{
    if (s == t)
        return "0";

    std::map<ll, ll> map;
    std::queue<ll> q;

    // BFS
    bool can = false;
    q.push(s);
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        if (top > 1e9)
            continue;
        if (top == t)
        {
            can = true;
            break;
        }

        if (!map.count(top * top))
        {
            map[top * top] = top;
            q.push(top * top);
        }
        if (!map.count(2 * top))
        {
            map[2 * top] = top;
            q.push(2 * top);
        }
        if (top != 1 && !map.count(1))
        {
            map[1] = top;
            q.push(1);
        }
    }

    if (!can)
        return "-1";
    // 정답 만들기
    auto cur = t;
    std::stack<char> st;
    while (cur != s)
    {
        auto &next = map[cur];
        if (cur == next * next)
        {
            st.push('*');
        }
        else if (cur == next + next)
        {
            st.push('+');
        }
        else if (next == 1)
        {
            st.push('-');
        }
        else if (next == s)
        {
            st.push('/');
        }
        cur = next;
    }
    std::string ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    ll s, t;
    std::cin >> s >> t;
    std::cout << solve(s, t);
}