#include <bits/stdc++.h>

struct block
{
    int no, width, height, weight;
    block(int no, int width, int height, int weight) : no(no), width(width), height(height), weight(weight) {}
};

int n, dp[100], track[100]; // i번 블럭을 맨 아레 두었을 때의 최대 높이
std::vector<block> blocks;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int width, height, weight;
        std::cin >> width >> height >> weight;
        blocks.emplace_back(block(i + 1, width, height, weight));
    }
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        dp[i] = blocks[i].height;
    }
}

void solve()
{
    // 무게의 내림차순으로 정렬
    std::sort(blocks.begin(), blocks.end(), [](const block &a, const block &b)
              { return a.weight > b.weight; });
    init();

    // 현재 값 또는 dp[j] 맨 위에 i번 블럭을 놓았을 때
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (blocks[j].width > blocks[i].width &&
                dp[j] + blocks[i].height > dp[i])
            {
                dp[i] = dp[j] + blocks[i].height;
            }
        }
    }

    int max_height = -1;
    for (int i = 0; i < n; i++)
    {
        max_height = std::max(max_height, dp[i]);
    }

    std::vector<int> answers;
    for (int i = n - 1; i >= 0; i--)
    {
        if (max_height == dp[i])
        {
            answers.push_back(blocks[i].no);
            max_height -= blocks[i].height;
        }
    }

    std::cout << answers.size() << '\n';
    for (auto &ans : answers)
        std::cout << ans << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}