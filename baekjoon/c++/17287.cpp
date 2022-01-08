#include <bits/stdc++.h>
using namespace std;

bool openbracket(char &c)
{
    return c == '{' || c == '[' || c == '(';
}
bool closebracket(char &c)
{
    return c == '}' || c == ']' || c == ')';
}
int solve(string &s)
{
    map<char, int> m;
    m['['] = m[']'] = 3;
    m['{'] = m['}'] = 2;
    m['('] = m[')'] = 1;

    int curscore = 0, maxscore = 0;
    for (auto &c : s)
    {
        if (isdigit(c))
            maxscore = max(maxscore, curscore);
        else if (openbracket(c))
            curscore += m[c];
        else //close bracket
            curscore -= m[c];
    }

    return maxscore;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    cout << solve(s);
}