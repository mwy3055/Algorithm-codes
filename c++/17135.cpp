#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Coord;
int n, m, d, archer[3];
vector<Coord> enemies;

bool cmp(Coord &a, Coord &b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
int distance(int a, Coord &c)
{
    return abs(n - c.first) + abs(archer[a] - c.second);
}
int solve()
{
    static Coord NONE(-1, -1);
    int cnt = 0;
    vector<Coord> left = enemies;

    for (int i = 0; i < n; i++)
    {
        if (left.empty())
            break;
        vector<int> dist(3, 0x7fffffff);
        vector<Coord> shot(3, NONE);
        // select enemy to shot
        for (int j = 0; j < 3; j++)
        {
            for (auto &enemy : left)
            {
                int dis = distance(j, enemy);
                if (dis <= d && dis < dist[j])
                {
                    shot[j] = enemy;
                    dist[j] = dis;
                }
                else if (dis == dist[j] && enemy.second < shot[j].second)
                {
                    shot[j] = enemy;
                }
            }
        }

        for (auto toshot : shot)
        {
            auto it = find(left.begin(), left.end(), toshot);
            if (toshot != NONE && (it != left.end()))
            {
                left.erase(it);
                cnt++;
            }
        }

        vector<vector<Coord>::iterator> eraselist;
        for (auto it = left.begin(); it != left.end(); it++)
        {
            if ((*it).first == n - 1)
                eraselist.push_back(it);
            else
                (*it).first++;
        }
        reverse(eraselist.begin(), eraselist.end());
        for (auto it : eraselist)
            left.erase(it);
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int t;
            cin >> t;
            if (t)
                enemies.push_back(Coord(i, j));
        }
    }

    sort(enemies.begin(), enemies.end());
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        archer[0] = i;
        for (int j = i + 1; j < m; j++)
        {
            archer[1] = j;
            for (int k = j + 1; k < m; k++)
            {
                archer[2] = k;
                ans = max(ans, solve());
            }
        }
    }
    cout << ans;
}