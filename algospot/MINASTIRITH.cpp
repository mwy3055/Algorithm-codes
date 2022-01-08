#include <bits/stdc++.h>

using pdd = std::pair<double, double>;
const int INF = 0x3f3f3f3f;

struct post
{
    double y, x, r;
    post(double y = 0, double x = 0, double r = 0) : y(y), x(x), r(r) {}
};

const double pi = 2 * acos(0);

int solve_linear(std::vector<pdd> &ranges, double begin, double end)
{
    int n = ranges.size();
    int count = 0, index = 0;
    while (begin < end)
    {
        // begin과 겹치는 구간 중 가장 멀리 가는 구간을 선택하자.
        double max_cover = -1;
        while (index < n && ranges[index].first <= begin)
        {
            max_cover = std::max(max_cover, ranges[index].second);
            index++;
        }
        // begin과 겹치는 구간이 없다면
        if (max_cover <= begin)
            return INF;
        begin = max_cover;
        count++;
    }

    return count;
}

int solve(int &n, std::vector<post> &posts)
{
    // 초소가 감시할 수 있는 각의 범위를 저장 (begin, end)
    std::vector<pdd> ranges;
    for (auto &post : posts)
    {
        // loc: x축의 양의 방향과 초소의 중심이 이루는 각
        // [-pi, pi] 범위의 값을 [0, 2*pi] 범위로 정규화 (fmod)
        auto loc = std::fmod(2 * pi + std::atan2(post.y, post.x), 2 * pi);
        // range: 초소가 좌우로 감시할 수 있는 각의 크기
        auto range = 2 * std::asin(post.r / 16);
        ranges.emplace_back(loc - range, loc + range);
    }
    // 시작 위치가 작은 초소부터 오도록 정렬
    std::sort(ranges.begin(), ranges.end());

    int ans = INF;
    // 0(원을 자르는 점)이 문제!
    // 0을 지나는 구간 하나를 선택하고 나머지 부분을 잘 덮어보자.
    for (auto &range : ranges)
    {
        // 0을 지나는 구간이라면
        if (range.first <= 0 || range.second >= 2 * pi)
        {
            // 정규화하지 않으면 begin이 end보다 클 수도 있다.
            auto begin = std::fmod(range.second, 2 * pi);
            auto end = std::fmod(range.first + 2 * pi, 2 * pi);
            ans = std::min(ans, 1 + solve_linear(ranges, begin, end));
        }
    }
    return (ans == INF ? -1 : ans);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    for (int i = 0; i < c; i++)
    {
        int n;
        std::cin >> n;
        std::vector<post> posts(n);
        for (auto &post : posts)
            std::cin >> post.y >> post.x >> post.r;
        int ans = solve(n, posts);
        if (ans == -1)
            std::cout << "IMPOSSIBLE" << '\n';
        else
            std::cout << ans << '\n';
    }
}