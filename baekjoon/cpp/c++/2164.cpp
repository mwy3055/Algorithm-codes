#include <bits/stdc++.h>
using namespace std;
//??: front, ??:back
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> d;
    for (int i = 1; i <= n; i++)
        d.push_back(i);

    int t = d.front();
    while (true)
    {
        d.pop_front();
        if (d.empty())
            break;
        t = d.front();
        d.push_back(d.front());
        d.pop_front();
    }

    cout << t;
}