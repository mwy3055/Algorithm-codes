#include <iostream>
#include <deque>
using namespace std;

void left(deque<int> &d)
{
    int x = d.front();
    d.pop_front();
    d.push_back(x);
}
void right(deque<int> &d)
{
    int x = d.back();
    d.pop_back();
    d.push_front(x);
}
void pop(deque<int> &d, int &n)
{
    d.pop_front();
    n--;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    deque<int> d(n);
    for (int i = 1; i <= n; i++)
        d[i - 1] = i;

    int ans = 0;
    for (int a = 0; a < m; a++)
    {
        int t;
        cin >> t;
        if (d[0] == t)
        {
            pop(d, n);
            continue;
        }
        int i = 0;
        while (d[i] != t)
            i++;

        if (i < n - i)
        {
            for (int j = 0; j < i; j++)
                left(d);
            ans += i;
            pop(d, n);
        }
        else
        {
            for (int j = 0; j < n - i; j++)
                right(d);
            ans += n - i;
            pop(d, n);
        }
        /* debug */
        /*       int siz = d.size();
        for (int k = 0; k < siz; k++)
            cout << d[k] << " ";
        cout << '\n';
        /* debug end */
    }
    cout << ans;
}