#include <bits/stdc++.h>

int n, k;
int p[100001], a[100001];
int count[10][101];

void getinput()
{
    std::memset(p, 0, sizeof(p));
    std::memset(a, 0, sizeof(a));
    std::memset(count, 0, sizeof(count));

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i] >> a[i];
    }
}

int solve()
{
    int ans = 0;
    for (int i = 1; i < k; i++)
    {
        count[p[i]][a[i]]++;
    }
    for (int i = k; i <= n; i++)
    {
        count[p[i]][a[i]]++;
        count[p[i - k]][a[i - k]]--;

        bool checked[10] = {false};
        int player_count = 0, tsum = 0;
        for (int ab = 100; ab > 0; ab--)
        {
            for (int pos = 1; pos <= 9; pos++)
            {
                if (count[pos][ab] > 0 && !checked[pos])
                {
                    player_count++;
                    checked[pos] = true;
                    tsum += ab;
                }
                if (player_count == 9)
                    break;
            }
            if (player_count == 9)
                break;
        }
        if (player_count == 9)
        {
            ans = std::max(ans, tsum);
        }
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        getinput();
        std::cout << solve() << '\n';
    }
}