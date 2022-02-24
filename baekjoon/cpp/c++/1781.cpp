#include <bits/stdc++.h>

// first: 데드라인
// second: 컵라면 수
using pii = std::pair<int, int>;

int solve(int n, std::vector<pii> &problems)
{
    // 컵라면 값이 큰 순서대로 정렬
    std::priority_queue<int> pq;

    std::sort(problems.begin(), problems.end());
    // 데드라인 뒤에서부터 뽑는 이유
    // 데드라인이 먼 문제는 빨리 풀어도 되지만
    // 데드라인이 짧은 문제는 나중에 풀 수 없음
    int ans = 0, index = n - 1;
    for (int time = n; time >= 1; time--)
    {
        while (index >= 0 && problems[index].first == time)
            pq.push(problems[index--].second);
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<pii> problems;
    for (int i = 0; i < n; i++)
    {
        int d, c;
        std::cin >> d >> c;
        problems.emplace_back(d, c);
    }
    std::cout << solve(n, problems) << '\n';
}
