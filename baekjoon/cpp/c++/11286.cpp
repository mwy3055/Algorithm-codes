#include <bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, cmp> pq;

    int n;
    cin >> n;
    while (n--)
    {
        int op;
        cin >> op;
        if (op)
        {
            pq.push(op);
        }
        else if (!op)
        {
            if (pq.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                int top = pq.top();
                cout << top << '\n';
                pq.pop();
            }
        }
    }
}