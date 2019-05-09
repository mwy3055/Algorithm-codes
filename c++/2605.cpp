#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    list<int> l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        list<int>::iterator it = l.begin();
        while (r--)
            it++;
        l.insert(it, i + 1);
    }

    reverse(l.begin(), l.end());
    for (int &i : l)
        cout << i << ' ';
}