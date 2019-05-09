#include <bits/stdc++.h>
using namespace std;

void bf(int &n, int &m, int dep, vector<int> &v, bool *contains)
{
    if (v.size() == m)
    {
        for (int &i : v)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    if (dep == n)
        return;

    for (int i = 0; i < n; i++)
    {
        if (contains[i] == false)
        {
            contains[i] = true;
            v.push_back(i + 1);

            bf(n, m, dep + 1, v, contains);
            contains[i] = false;
            v.pop_back();
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    bool contains[8] = {false};
    vector<int> v;
    cin >> n >> m;
    bf(n, m, 0, v, contains);
}