#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        string w;
        cin >> w;
        int n;
        cin >> n;
        vector<string> input, ans;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            input.push_back(s);
        }
        string pattern;
        for (auto &cw : w)
        {
            if (cw == '?')
                pattern.push_back('.');
            else if (cw == '*')
            {
                pattern.push_back('.');
                pattern.push_back('*');
            }
            else
                pattern.push_back(cw);
        }

        regex re(pattern);
        for (auto &i : input)
            if (regex_match(i, re))
                ans.push_back(i);
        sort(ans.begin(), ans.end());
        for (auto &answer : ans)
            cout << answer << '\n';
    }
}