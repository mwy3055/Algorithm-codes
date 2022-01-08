#include <bits/stdc++.h>
using namespace std;

int gethash(int *num, int &m)
{
    int hash = 0;
    for (int i = 0; i < m; i++)
    {
        hash = hash * 10 + num[i];
    }
    return hash;
}

int main()
{
    int num[8];
    set<int> s;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    do
    {
        int hash = gethash(num, m);
        if (s.find(hash) == s.end())
        {
            for (int i = 0; i < m; i++)
                cout << num[i] << ' ';
            cout << '\n';
            s.insert(hash);
        }
    } while (next_permutation(num, num + n));
}