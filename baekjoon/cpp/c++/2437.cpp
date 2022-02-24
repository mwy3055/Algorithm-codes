#include <bits/stdc++.h>

int n;
std::vector<int> weights;

int solve()
{
    std::sort(weights.begin(), weights.end());
    if (weights[0] != 1)
        return 1;
    // 1부터 sum까지의 무게를 모두 만들 수 있을 때,
    // w <= sum(적어도 하나의 w 이상의 값을 만드는 데 w가 필요하지 않음) 또는
    // sum = w - 1이라면(구간이 이어짐)
    // [sum, sum + w] 구간의 무게를 모두 만들 수 있다.
    // 그렇지 않다면, (sum + 1)이 정답이다.
    // sum까지는 만들 수 있으나 sum + 1을 만들 방법이 없기 때문이다.
    // 이때 sum보다 큰 수 중 만들 수 있는 가장 작은 수는 w이다.
    int sum = weights[0];
    for (int i = 1; i < n; i++)
    {
        auto &w = weights[i];
        if (w <= sum || sum + 1 == w)
            sum = sum + w;
        else
            break;
    }
    return sum + 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    weights.resize(n);
    for (auto &w : weights)
        std::cin >> w;
    std::cout << solve() << '\n';
}