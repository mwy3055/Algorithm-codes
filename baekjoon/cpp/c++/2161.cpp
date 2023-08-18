#include <bits/stdc++.h>
using namespace std;
//À§: front, ¹Ø:back
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> d;
    for (int i = 1; i <= n; i++)
        d.push_back(i);

    while (true)
    {
        cout << d.front() << ' ';
        d.pop_front();
        if (d.empty())
            break;
        d.push_back(d.front());
        d.pop_front();
    }
}