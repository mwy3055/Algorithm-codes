#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair<int, int>;

ll n;
std::vector<ll> b, answer;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll elem;
        std::cin >> elem;
        b.push_back(elem);
    }
}

int find(ll v)
{
    auto it = std::find(b.begin(), b.end(), v);
    if (it != b.end())
    {
        return it - b.begin();
    }
    else
    {
        return -1;
    }
}

bool search(ll cur, int count)
{
    answer.push_back(cur);
    if (count == n)
    {
        for (auto &a : answer)
            std::cout << a << ' ';
        std::cout << '\n';
        return true;
    }

    bool found = false;
    if (cur % 3 == 0 && find(cur / 3) != -1)
    {
        found = search(cur / 3, count + 1);
    }

    if (find(cur * 2) != -1)
    {
        found = search(cur * 2, count + 1);
    }
    answer.pop_back();
    return found;
}

void solve()
{
    int sidx = -1;
    for (int i = 0; i < n; i++)
    {
        bool exists = false;
        if (find(b[i] * 3) != -1)
        {
            exists = true;
        }
        if (b[i] % 2 == 0 && find(b[i] / 2) != -1)
        {
            exists = true;
        }
        if (!exists)
        {
            sidx = i;
            break;
        }
    }

    search(b[sidx], 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}