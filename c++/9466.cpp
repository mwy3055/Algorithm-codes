#include <bits/stdc++.h>
using namespace std;

bool iscycle(int *choice, bool *checked, bool *curcheck, int &start, int cur, int &dep)
{
    if (start == cur) //����Ŭ ����
    {
        checked[start] = true;
        return true;
    }
    if (curcheck[cur]) //����Ŭ ���� �Ұ�
        return false;

    dep++;
    curcheck[cur] = true;
    if (iscycle(choice, checked, curcheck, start, choice[cur], dep))
    {
        checked[cur] = true;
        return true;
    }
    else
    {
        return false;
    }
}

int solve()
{
    int n, choice[100000], ans;
    bool checked[100000] = {false};
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> choice[i];
        if (i == --choice[i])
        {
            ans--;
            checked[i] = true;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (checked[i])
            continue;

        bool curcheck[100000] = {false};
        int dep = 1;
        if (iscycle(choice, checked, curcheck, i, choice[i], dep))
            ans -= dep;
    }
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