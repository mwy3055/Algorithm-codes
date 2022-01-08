#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

struct object
{
    string s;
    int v, like;
};

int solve(int &n, int &w, vector<object> &objs, vector<int> &ans)
{
    vvi dp(n, vector<int>(w + 1, 0)), track(n, vector<int>(w + 1, -1)); // -1: 선택하지 않음, else: 선택한 물건의 인덱스
    dp[0][objs[0].v] = objs[0].like;
    track[0][objs[0].v] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (j - objs[i].v >= 0)
            {
                int &no = dp[i - 1][j], select = dp[i - 1][j - objs[i].v] + objs[i].like;
                dp[i][j] = max(no, select);
                if (no < select)
                    track[i][j] = i;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int mlike = 0, mval = 0;
    for (int i = 1; i <= w; i++)
    {
        if (mlike < dp[n - 1][i])
        {
            mlike = dp[n - 1][i];
            mval = i;
        }
    }
    int idx = n - 1, cval = mval;
    while (0 <= idx)
    {
        if (track[idx][cval] == idx)
        {
            ans.push_back(idx);
            cval -= objs[idx].v;
        }
        idx--;
    }
    return mlike;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    while (c--)
    {
        int n, w;
        cin >> n >> w;
        vector<object> objs(n);
        vector<int> ans;
        for (auto &obj : objs)
            cin >> obj.s >> obj.v >> obj.like;
        int mval = solve(n, w, objs, ans);
        cout << mval << ' ' << ans.size() << '\n';
        for (auto &comp : ans)
            cout << objs[comp].s << '\n';
    }
}