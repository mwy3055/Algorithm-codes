#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool first[1001][1001], second[1001][1001];

void getinput(int n, int m, vi &limits)
{
    for (int i = 1; i <= m; i++)
        cin >> limits[i];
    for (int i = 1; i <= n; i++)
    {
        int req;
        cin >> req;
        while (req != -1)
        {
            first[i][req] = true;
            cin >> req;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int req, cnt = 0;
        cin >> req;
        while (req != -1)
        {
            second[i][req] = true;
            cin >> req;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vi limits(m + 1);
    getinput(n, m, limits);

    vvi success(n + 1, vi());
    vvi count(m + 1, vi());
    vi size(m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (first[i][j])
                count[j].push_back(i);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        int siz = count[j].size();
        limits[j] -= siz;
        if (siz && 0 <= limits[j])
        {
            for (auto &i : count[j])
            {
                success[i].push_back(j);
            }
        }
    }

    for (auto &c : count)
        c.clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (second[i][j])
                count[j].push_back(i);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        int siz = count[j].size();
        if (siz && siz <= limits[j])
        {
            for (auto &i : count[j])
            {
                success[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (success[i].size() == 0)
        {
            cout << "¸ÁÇß¾î¿ä" << '\n';
            continue;
        }
        sort(success[i].begin(), success[i].end());
        for (auto &get : success[i])
            cout << get << ' ';
        cout << '\n';
    }
}