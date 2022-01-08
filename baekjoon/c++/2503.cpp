#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;

Pair check(string cr, string n) // cr이 기준, n을 비교
{
    Pair rtn(0, 0);

    for (int i = 0; i < 3; i++)
    {
        if (cr[i] == n[i])
            rtn.first++;
        else if (cr[i] == n[(i + 1) % 3] || cr[i] == n[(i + 2) % 3])
            rtn.second++;
    }

    return rtn;
}

bool check2(int n) // n이 게임에서 등장할 수 있는 수인가? e.g. 0이 들어간 숫자는 제외(100)
{
    int a = n / 100, b = (n % 100) / 10, c = n % 10;
    return a != b && a != c && b != c && a != 0 && b != 0 && c != 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool avail[1001];
    memset(avail, true, sizeof(bool) * 1001);

    int n;
    vector<pair<string, Pair>> response;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string num;
        Pair score;
        cin >> num >> score.first >> score.second;
        response.push_back(make_pair(num, score));
    }

    for (auto &res : response)
    {
        string &num = res.first;
        Pair &score = res.second;
        for (int i = 100; i < 1000; i++)
        {
            if (!avail[i] || (i % 100 == 0 || (i % 100) / 10 == 0 || i % 10 == 0))
                continue;
            if (check(to_string(i), num) != score)
            {
                avail[i] = false;
            }
        }
    }

    int ans = 0;
    for (int i = 100; i < 1000; i++)
    {
        if (avail[i] && check2(i))
        {
            ans++;
        }
    }
    cout << ans;
}