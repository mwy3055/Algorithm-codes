#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n;
std::vector<int> weights;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w;
        std::cin >> w;
        weights.push_back(w);
    }
}

int solve()
{
    int ans = 0;
    std::vector<pii> s; // value, index
    std::deque<pii> d;

    for (int i = 0; i < n; i++)
    {
        // 내 앞에 나보다 큰 게 있다면
        if (!d.empty() && d.back().first > weights[i])
        {
            // 나보다 작은 공을 모두 체크
            while (!d.empty() && d.front().first < weights[i])
            {
                s.push_back(d.front());
                d.pop_front();
            }
            s.emplace_back(weights[i], i);
            d.emplace_front(weights[i], i);
        }
        else
        {
            d.emplace_back(weights[i], i);
        }
    }

    std::sort(s.begin(), s.end());
    return std::unique(s.begin(), s.end()) - s.begin();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}