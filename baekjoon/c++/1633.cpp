#include <bits/stdc++.h>

struct player
{
    int w, b;
    player(int w, int b, int index) : w(w), b(b) {}
};

int dp[1000][16][16];
std::vector<player> players;

void init()
{
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 16; j++)
            memset(dp[i][j], -1, sizeof(int) * 16);
}

int solve(int idx, int bleft, int wleft)
{
    if (idx == players.size())
        return 0;
    auto &ret = dp[idx][bleft][wleft];
    if (ret != -1)
        return ret;

    ret = solve(idx + 1, bleft, wleft);
    if (bleft)
        ret = std::max(ret, solve(idx + 1, bleft - 1, wleft) + players[idx].b);
    if (wleft)
        ret = std::max(ret, solve(idx + 1, bleft, wleft - 1) + players[idx].w);
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();

    int b, w, idx = 0;
    while (std::cin >> w >> b)
        players.emplace_back(w, b, idx++);
    std::cout << solve(0, 15, 15) << '\n';
}