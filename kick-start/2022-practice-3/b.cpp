#include <bits/stdc++.h>

int n;
std::vector<int> v;

void getinput()
{
    v.clear();
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int vi;
        std::cin >> vi;
        v.push_back(vi);
    }
}

bool check1(int day, int prev_max)
{
    return day == 0 || v[day] > prev_max;
}

bool check2(int day)
{
    return day == n - 1 || v[day] > v[day + 1];
}

int solve()
{
    int ans = 0, prev_max = -1;
    for (int i = 0; i < n; i++)
    {
        if (check1(i, prev_max) && check2(i))
        {
            ans++;
        }
        prev_max = std::max(prev_max, v[i]);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        getinput();
        int answer = solve();
        std::cout << "Case #" << i << ": " << answer << '\n';
    }
}