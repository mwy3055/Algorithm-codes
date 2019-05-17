#include <bits/stdc++.h>
using namespace std;

void make_nth(int &n)
{
    int k;
    cin >> k;

    list<int> l;
    for (int i = 1; i <= n; i++)
    {
        int ith = k % i;
        k /= i;
        list<int>::iterator it = l.begin();
        while (ith--)
            it++;
        l.insert(it, i);
    }

    for (int &i : l)
        cout << i << ' ';
}

void calculate_nth(int &n)
{
    list<int> l;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        l.push_back(t);
    }

    int m = 0;
    for (int i = n; i >= 1; i--)
    {
        int ith = distance(find(l.begin(), l.end(), i), l.begin());
        m = m * n + ith;
    }

    cout << m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, prob;
    cin >> n >> prob;
    if (prob == 1)
        make_nth(n);
    else
        calculate_nth(n);
}