#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v(20);
    for (int i = 0; i < 20; i++)
        v[i] = i + 1;

    for (int i = 0; i < 10; i++)
    {
        int s, e;
        cin >> s >> e;
        reverse(v.begin() + s - 1, v.begin() + e);
    }

    for (int &i : v)
        cout << i << ' ';
}