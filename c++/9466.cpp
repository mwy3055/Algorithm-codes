#include <bits/stdc++.h>
using namespace std;

void dfs(int *select, char *state, stack<int> &s, int cur)
{
    char &ref = state[cur];

    if (ref == 3)
    {
        while (s.top() != cur)
        {
            state[s.top()] = 1;
            s.pop();
        }
        ref = 1;
        s.pop();

        while (!s.empty())
        {
            state[s.top()] = 2;
            s.pop();
        }
        return;
    }
    else if (ref == 2)
    {
        while (!s.empty())
        {
            state[s.top()] = 2;
            s.pop();
        }
        return;
    }

    ref = 3;
    s.push(cur);
    dfs(select, state, s, select[cur]);
}
int solve()
{
    int n;
    cin >> n;
    int *select = new int[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> select[i];

    char *state = new char[n + 1];
    memset(state, 0, (n + 1) * sizeof(char));
    stack<int> s;

    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
            dfs(select, state, s, i);

        if (state[i] == 1)
            ans--;
    }

    delete[] select;
    delete[] state;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
}