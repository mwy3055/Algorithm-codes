#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        if (op == 0 && q.empty())
            cout << 0 << '\n';
        else if (op == 0)
        {
            cout << q.top() << '\n';
            q.pop();
        }
        else
        {
            q.push(op);
        }
    }
}