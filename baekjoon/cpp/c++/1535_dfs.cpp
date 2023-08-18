#include <bits/stdc++.h>
using namespace std;

int ans, n;
int hloss[20], hget[20];

void dfs(int dep, int health, int happ)
{
    if (health <= 0)
        return;
    if (dep == n)
    {
        ans = max(ans, happ);
        return;
    }

    dfs(dep + 1, health - hloss[dep], happ + hget[dep]);
    dfs(dep + 1, health, happ);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> hloss[i];
    for (int i = 0; i < n; i++)
        cin >> hget[i];

    dfs(0, 100, 0);
    cout << ans;
}