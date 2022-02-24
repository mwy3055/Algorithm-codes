#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    deque<int> q;

    int n;
    string op;
    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            q.push_back(x);
        }
        else if (op == "pop")
        {
            if (q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop_front();
            }
        }
        else if (op == "size")
        {
            cout << q.size() << '\n';
        }
        else if (op == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (op == "front")
        {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        }
        else if (op == "back")
        {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
        else
            exit(1);
    }
}