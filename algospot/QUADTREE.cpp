#include <bits/stdc++.h>
using namespace std;

string solve(string::iterator &it)
{
    char head = *(it++);
    if (head != 'x')
        return string(1, head);

    string upleft = solve(it);
    string upright = solve(it);
    string downleft = solve(it);
    string downright = solve(it);
    return 'x' + downleft + downright + upleft + upright;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        string str;
        cin >> str;
        string::iterator it = str.begin();
        cout << solve(it) << '\n';
    }
}