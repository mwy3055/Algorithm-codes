#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n;
std::vector<pii> a;

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        std::cin >> v;
        a.emplace_back(v, i);
    }
}

int solve()
{
    /*
        버블 정렬은 매 정렬마다 가장 큰 값이 맨 뒤로 간다.
        (정렬의 횟수) = (모든 원소가 자기 자리를 찾아가는 데 걸리는 시간)
                     = (가장 많이 이동한 값이 이동한 거리)
                     이때, 왼쪽으로 이동한 값만 고려해야 한다.
                     오른쪽으로 이동한 값은 한 번에 가기 때문.
    */
    std::sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = std::max(ans, a[i].second - i);
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