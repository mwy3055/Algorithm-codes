#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, num[8];
vector<int> push;
set<string> s;

string gethash()
{
    string hash;
    for (auto n : push)
    {
        while (n)
        {
            hash.push_back((char)(n % 10 + '0'));
            n /= 10;
        }
        hash.push_back(' ');
    }

    return hash;
}

void solve(int idx, int left) //골라야 하는 숫자의 수
{
    if (left == 0)
    {
        string hash = gethash();
        if (s.find(hash) != s.end())
            return;

        for (auto &p : push)
            cout << p << ' ';
        cout << '\n';
        s.insert(hash);
        return;
    }
    if (idx == n)
        return;

    for (int i = idx; i < n; i++)
    {
        push.push_back(num[i]);
        solve(i, left - 1);
        push.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    sort(num, num + n);

    solve(0, m);
}