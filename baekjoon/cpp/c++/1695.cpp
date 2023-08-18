#include <bits/stdc++.h>

int n, arr[5001];
int cur[5001], before[5001];

void getinput()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }
}

int solve()
{
    // n - (LCS of arr and its reverse)
    for (int i = 1; i <= n; i++)
    {
        std::memcpy(before, cur, sizeof(cur));
        std::memset(cur, 0, sizeof(cur));
        for (int j = 1; j <= n; j++)
        {
            if (arr[i] == arr[n - j + 1])
            {
                cur[j] = before[j - 1] + 1;
            }
            else
            {
                cur[j] = std::max(cur[j - 1], before[j]);
            }
        }
    }
    return n - cur[n];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}
