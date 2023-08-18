#include <bits/stdc++.h>

int n, x;
std::vector<int> a;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        a.push_back(val);
    }
    std::cin >> x;
}

int solve()
{
    std::sort(a.begin(), a.end());
    int l = 0, r = n - 1, ans = 0;
    while (l < r)
    {
        auto val = a[l] + a[r];
        if (val == x)
        {
            ans++;
            l++, r--;
        }
        else if (val < x)
        {
            l++;
        }
        else if (val > x)
        {
            r--;
        }
        else
            exit(-1);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}