#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int m;
std::vector<pii> segments;

void getinput()
{
    std::cin >> m;
    int l, r;
    while (true)
    {
        std::cin >> l >> r;
        if (l == 0 && r == 0)
            break;
        segments.emplace_back(l, r);
    }
}

// 가장 오른쪽으로 멀리 가는 선분을 고르자.
int solve()
{
    int n = segments.size();
    std::sort(segments.begin(), segments.end());

    int count = 0, index = 0;

    // 0 왼쪽에 있는 선분은 전부 거름
    while (index < n && segments[index].second <= 0)
        index++;
    // 전부 0 왼쪽에 있다면
    if (index == n)
        return 0;

    // 선분을 고르자.
    // begin과 겹치는 선분 중 가장 오른쪽으로 멀리 가는 선분을 찾자.
    int begin = 0, end = m;
    while (begin < end)
    {
        int rightmost = -1;
        while (index < n && segments[index].first <= begin)
        {
            rightmost = std::max(rightmost, segments[index].second);
            index++;
        }
        // 겹치는 선분이 없다면: 덮을 수 없음
        if (rightmost == -1)
        {
            return 0;
        }
        begin = rightmost;
        count++;
    }
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}