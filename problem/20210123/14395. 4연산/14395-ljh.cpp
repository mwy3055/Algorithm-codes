#include <bits/stdc++.h>

using ll = long long;

using namespace std;

bool flag = false; //목표하는 수와 계산결과 같아졌음을 알리는 flag

ll s, e;
string oc[] = {"*", "+", "-", "/"}; //order of calculation
set<ll> Set;

ll calculate(ll a, int idx)
{
    if (idx == 0)
        return (a * a);
    else if (idx == 1)
        return (a + a);
    else if (idx == 2)
        return (a - a);
    else if (idx == 3)
        return (a / a);
}

string bfs()
{
    queue<pair<ll, string>> q;
    q.push(make_pair(s, ""));
    Set.insert(s);

    while (q.empty() == 0)
    {
        ll x = q.front().first;
        string ans = q.front().second;
        q.pop();

        if (x == e)
        {
            flag = true;
            return ans;
        }
        for (int i = 0; i < 4; i++)
        {
            ll nx = calculate(x, i);

            if (nx < 1)
                continue;

            //set.find() 원소 nx 가 없다면 s.end()와 같은 값을 반환
            //즉, set에 이미 있는 결과라면 pass
            //중복을 체크하려는 것 
            if (Set.find(nx) != Set.end())
                continue;

            Set.insert(nx);

            q.push(make_pair(nx, ans + oc[i]));
        }
    }
    return "didn't get to the flag";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> e;
    if (s == e)
    {
        cout << 0 << '\n';
        exit(0);
    }

    string result = bfs();

    if (flag == true)
        cout << result << '\n';
    else
        cout << "-1" << '\n';

    return 0;
}
