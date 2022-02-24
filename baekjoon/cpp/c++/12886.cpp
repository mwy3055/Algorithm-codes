#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> node;
bool visit[1000][1000];

int solve(int a, int b, int c)
{
    if ((a + b + c) % 3)
        return 0;

    int sum = a + b + c;
    queue<node> q;

    q.push(node(a, b));
    visit[a][b] = true;
    while (!q.empty())
    {
        auto top = q.front();
        auto &x = top.first, &y = top.second;
        q.pop();
        auto z = sum - x - y;
        if (x == y && y == z)
            return 1;

        int nx[] = {x, y, y}, ny[] = {y, z, z};
        for (int i = 0; i < 3; i++)
        {
            int na = nx[i], nb = ny[i];
            if (na == nb)
                continue;
            else if (na < nb)
            {
                nb -= na;
                na *= 2;
            }
            else
            {
                na -= nb;
                nb *= 2;
            }
            int nc = sum - na - nb;
            int tmax = max(na, max(nb, nc)), tmin = min(na, min(nb, nc));
            if (!visit[tmax][tmin])
            {
                visit[tmax][tmin] = true;
                q.push(node(tmax, tmin));
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << solve(a, b, c);
}