#include <bits/stdc++.h>

using ll = long long;
using pll = std::pair<ll, ll>; // size, price

int n;
std::vector<pll> paints;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        std::cin >> a >> b;
        paints.emplace_back(a, b);
    }
}

ll solve()
{
    // 일단 크기 순서대로 정렬
    std::sort(paints.begin(), paints.end());
    // ans: 0~(i-1)까지의 정답
    // temp_ans: i번을 고를 때의 정답
    auto ans = paints[0].second;
    auto temp_ans = paints[0].second;
    for (int i = 1; i < n; i++)
    {
        // i를 넣는 경우의 수:
        // 1) 0~(i-1)에 i를 추가하는 경우
        // 2) i 하나만 고르는 경우
        if (temp_ans > paints[i].first - paints[i - 1].first)
        {
            // (i-1)은 더이상 max_size가 아님. 따라서 더해줌.
            // 새로운 max_size는 i. 따라서 뺌.
            temp_ans = temp_ans + paints[i].second - paints[i].first + paints[i - 1].first;
        }
        else
        {
            temp_ans = paints[i].second;
        }
        // max(i를 넣지 않는 경우, i를 넣는 경우)
        ans = std::max(ans, temp_ans);
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