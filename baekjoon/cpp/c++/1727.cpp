#include <bits/stdc++.h>

int n, m;
std::vector<int> a, b;

const int INF = 0x3f3f3f3f;
int dp[1000][1000];

void getinput()
{
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        a.emplace_back(c);
    }
    for (int i = 0; i < m; i++)
    {
        int c;
        std::cin >> c;
        b.emplace_back(c);
    }
}

// a[aidx, n)과 b[bidx, m)를 매칭
int search(int aidx, int bidx)
{
    // 매칭 끝
    if (aidx >= n)
        return 0;
    auto &ret = dp[aidx][bidx];
    if (ret != -1)
        return ret;

    // a에 남아있는 사람이 더 적다고 가정
    // a에 남아있는 사람이 더 많다면 매칭하지 않음 (for문 조건에 의해)
    ret = INF;
    for (int i = bidx; m - i >= n - aidx; i++)
    {
        ret = std::min(ret, std::abs(a[aidx] - b[i]) + search(aidx + 1, i + 1));
    }
    return ret;
}

int solve()
{
    std::memset(dp, -1, sizeof(dp));

    // 오름차순으로 정렬하는 게 최적: 매칭이 서로 교차하지 않음
    // 매칭이 교차한다면, 교차하는 매칭을 풀어서 더 나은 해를 만들 수 있음
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // 무조건 a가 b보다 많지 않다고 가정
    if (n > m)
    {
        std::swap(n, m);
        std::swap(a, b);
    }
    return search(0, 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}