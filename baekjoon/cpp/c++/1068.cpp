#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &childs, int &cur, int &remove, int &ans)
{
    if (cur == remove)
        return;
    if (childs[cur].size() == 0 || (childs[cur].size() == 1 && childs[cur][0] == remove)) //리프 노드 또는 자식이 remove뿐인 부모 노드
    {
        ans++;
        return;
    }

    for (int &child : childs[cur])
        solve(childs, child, remove, ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, root;
    cin >> n;
    vector<vector<int>> childs(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == -1)
            root = i;
        else
            childs[t].push_back(i);
    }

    int rm, ans = 0;
    cin >> rm;

    solve(childs, root, rm, ans);

    cout << ans;
}