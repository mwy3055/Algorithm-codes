#include <bits/stdc++.h>

using ll = long long;
using vll = std::vector<ll>;

int n, c;
vll weights;

void getinput()
{
    std::cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        int w;
        std::cin >> w;
        weights.push_back(w);
    }
}

void split(vll &v, int left, int right) // [left, right)
{
    int count = right - left;
    for (int bitmask = 0; bitmask < (1 << count); bitmask++)
    {
        ll sum = 0;
        for (int i = 0; i < count; i++)
        {
            if (bitmask & (1 << i))
                sum += weights[left + i];
        }
        v.push_back(sum);
    }
    std::sort(v.begin(), v.end());
}

// 무게를 절반으로 쪼갠 후, 각 부분에서 가능한 모든 무게의 집합을 찾는다.
// 집합을 각각 오름차순 정렬한 후, 하나는 왼쪽에서부터, 하나는 오른쪽에서부터 투 포인터로 탐색한다.
// i가 주어질 때 a[i]+b[j] <= c를 만족하는 최대의 j를 찾는다.
// 이때 주어진 식을 b[0]~b[j]가 만족하므로 정답에 (j+1)을 더할 수 있다.
// 모든 i에 대해 j값을 찾으면 된다.
int solve()
{
    int ans = 0;
    vll a, b;
    split(a, 0, n / 2);
    split(b, n / 2, n);

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = b.size() - 1; j >= 0; j--)
        {
            ll sum = a[i] + b[j];
            if (sum <= c)
            {
                ans += j + 1;
                break;
            }
        }
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