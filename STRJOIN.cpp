#include <bits/stdc++.h>

using vi = std::vector<int>;

// 매번 가장 짧은 두 개의 문자열을 합한다.
int solve(int &n, vi &lengths)
{
    std::priority_queue<int, vi, std::greater<int>> pq(lengths.begin(), lengths.end());

    int ans = 0;
    while (pq.size() > 1)
    {
        auto a = pq.top();
        pq.pop();
        auto b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    return ans;
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
        vi lengths(n);
        for (auto &len : lengths)
            std::cin >> len;
        std::cout << solve(n, lengths) << '\n';
    }
}