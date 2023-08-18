#include <bits/stdc++.h>
using namespace std;

bool goodword()
{
    string s;
    cin >> s;
    stack<char> st;
    for (char &c : s)
    {
        if (!st.empty() && st.top() == c)
            st.pop();
        else
        {
            st.push(c);
        }
    }
    return st.empty();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    while (n--)
    {
        if (goodword())
            ans++;
    }
    cout << ans;
}