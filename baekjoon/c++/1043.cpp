#include <bits/stdc++.h>
using namespace std;

// returns true if a contains b
bool contains(set<int> &a, set<int> &b)
{
    for (auto &bb : b)
    {
        if (a.find(bb) != a.end())
            return true;
    }
    return false;
}
// insert all elements in b into a
void insert(set<int> &a, set<int> &b)
{
    for (auto &bb : b)
        a.insert(bb);
}
void preprocess(set<int> &knows, set<int> *party, int &m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (contains(knows, party[j]))
            {
                insert(knows, party[j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m;
    set<int> knows, party[m];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int temp;
        cin >> temp;
        knows.insert(temp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int temp;
            cin >> temp;
            party[i].insert(temp);
        }
    }

    preprocess(knows, party, m);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (!contains(knows, party[i]))
            ans++;
    }
    cout << ans;
}