#include <bits/stdc++.h>

std::string s;

void getinput()
{
    std::cin >> s;
}

int solve()
{
    std::stack<char> st;
    for (auto &c : s)
    {
        if (st.empty())
            st.push(c);
        else if (c == ')' && st.top() == '(')
            st.pop();
        else
            st.push(c);
    }
    return st.size();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}