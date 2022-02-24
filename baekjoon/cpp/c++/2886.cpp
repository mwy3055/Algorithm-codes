#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct chair
{
    int y, x;
    bool assigned;
    chair(int y, int x, bool ass = false) : y(y), x(x), assigned(ass) {}
};
typedef pair<int, int> pii;

int r, c, ans;
char board[100][101];
set<pii> people;
vector<chair> chairs;

int sq(int n)
{
    return n * n;
}
int dist(pii person, chair c)
{
    return sq(person.first - c.y) + sq(person.second - c.x);
}

void assign()
{
    int cnt = 0;
    while (true)
    {
        for (auto &c : chairs)
        {
            if (c.assigned)
                continue; // already assigned
            map<pii, int> min_dist;
            for (auto &p : people)
            {
                int mdist = INF;
                for (auto &c : chairs)
                {
                    if (c.assigned)
                        continue;
                    mdist = min(mdist, dist(p, c));
                }
                min_dist[p] = mdist;
            }
            int mdist = INF;
            for (auto p : people)
                mdist = min(mdist, dist(p, c));
            int count = 0;
            vector<pii> assigned_people;
            for (auto &p : people)
            {
                int d = dist(p, c);
                if (d == mdist && d == min_dist[p])
                {
                    count++;
                    assigned_people.push_back(p);
                }
            }

            for (auto assigned : assigned_people)
                people.erase(assigned);
            if (1 < count)
                ans++;
            if (count)
            {
                cnt++;
                c.assigned = true;
            }
        }
        if (cnt == chairs.size() || people.empty())
            break;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        cin >> board[i];
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'X')
                people.insert(pii(i, j));
            else if (board[i][j] == 'L')
                chairs.push_back(chair(i, j));
        }
    }

    // assign chair
    assign();
    cout << ans << '\n';
}