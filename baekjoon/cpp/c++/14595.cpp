#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n;
std::vector<pii> actions;

void getinput()
{
    int m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        actions.emplace_back(x, y);
    }
}

int solve()
{
    // 구간의 begin, end를 모두 합쳐서 연속된 구간이 몇 개인지 구하기
    // 처음에는 각 방이 모두 하나의 구간
    // 벽을 부수면 구간이 합쳐진다.
    std::vector<int> diff(n + 1, 0);
    for (auto &a : actions)
    {
        diff[a.first]++;
        diff[a.second]--;
    }

    int ans = 0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += diff[i];
        if (count == 0)
            ans++;
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