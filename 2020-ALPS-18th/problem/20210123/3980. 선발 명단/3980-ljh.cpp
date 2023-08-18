#include <bits/stdc++.h>

const int MAX = 11;
using namespace std;
 
int player[MAX+1][MAX+1];
bool check[MAX+1];
int tc, ans;
 
void initialize()
{
    ans = 0;
    memset(check, false, sizeof(check));
    memset(player, 0, sizeof(player));
}

void input()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cin >> player[i][j];
        }
    }
}

void dfs(int d, int sum)
{
    if (d == 11)
    {
         if (ans < sum)
            ans = sum;

        return;
    }
    for (int i = 0; i < 11; i++)
    {
        if (check[i] || !player[d][i]) continue;
        check[i] = true;
        dfs(d + 1, sum + player[d][i]);
        check[i] = false;
    }
}

void solution()
{
    dfs(0,0);
}

void solve()
{
    int tc;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
    {
        initialize();
        input();
        solution();

        cout << ans << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}

