#include <bits/stdc++.h>
using namespace std;

void solve(string &s)
{
    deque<char> left, right;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '-' && !left.empty())
            left.pop_back();
        else if (s[i] == '<' && !left.empty())
        {
            right.push_front(left.back());
            left.pop_back();
        }
        else if (s[i] == '>' && !right.empty())
        {
            left.push_back(right.front());
            right.pop_front();
        }
        else if (s[i] != '-' && s[i] != '<' && s[i] != '>')
        {
            left.push_back(s[i]);
        }
    }

    while (!left.empty())
    {
        cout << left.front();
        left.pop_front();
    }

    while (!right.empty())
    {
        cout << right.front();
        right.pop_front();
    }
    cout << '\n';
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
        solve(s);
    }
}