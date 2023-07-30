#include <bits/stdc++.h>

struct thing
{
    int weight, satis;
    thing(int w, int s) : weight(w), satis(s) {}
};

int n, m;
std::vector<thing> things;

// 물건이 최대 14개로 쪼개짐
int dp[1400][10001];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int v, c, k;
        std::cin >> v >> c >> k;

        int bitmask = 1;
        while (k > 0)
        {
            int count = std::min(k, bitmask);
            things.emplace_back(v * count, c * count);
            k -= count;
            bitmask <<= 1;
        }
    }
}

int solve()
{
    dp[0][things[0].weight] = things[0].satis;
    for (int i = 1; i < things.size(); i++)
    {
        for (int j = 0; j <= m; j++)
        {
            // i번째 물건을 넣거나 넣지 않아서 무게가 j가 된 경우
            if (j >= things[i].weight)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - things[i].weight] + things[i].satis);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int ans = 0;
    for (int j = 0; j <= m; j++)
    {
        ans = std::max(ans, dp[things.size() - 1][j]);
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