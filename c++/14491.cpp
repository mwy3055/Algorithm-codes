#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    stack<int> s;
    while (t)
    {
        s.push(t % 9);
        t /= 9;
    }
    if (t)
        s.push(t);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}