#include <bits/stdc++.h>

using ball = std::pair<int, int>; // color, size
using ll = long long;

int n;
std::vector<ball> balls;
ll smaller_all[200001]; // i보다 작은 공의 크기의 합

std::vector<int> sizes_by_color[200001]; // 각 색깔에 대해 공의 크기를 정렬
std::vector<int> smaller_color[200001];  // 각 색깔에 대해 자신보다 작은 공의 크기의 합

void preprocess()
{
    // 크기순으로 정렬
    auto temp = balls;
    std::sort(temp.begin(), temp.end(), [](const ball &a, const ball &b)
              {
                  if (a.second != b.second)
                      return a.second < b.second;
                  return a.first < b.first;
              });
    int cidx = 0;
    for (int i = 1; i <= 2000; i++)
    {
        int sum_size = 0;
        while (cidx < n && temp[cidx].second == i - 1)
            sum_size += temp[cidx++].second++;
        smaller_all[i] = smaller_all[i - 1] + sum_size;
    }

    for (auto &b : balls)
        sizes_by_color[b.first].push_back(b.second);
    for (int i = 1; i <= n; i++)
        std::sort(sizes_by_color[i].begin(), sizes_by_color[i].end());
    for (int i = 1; i <= n; i++)
    {
        if (!sizes_by_color[i].empty())
        {
            // 각 size마다 위에서 했던 smaller_all의 계산을 반복
            // sizes_by_color[i]의 값이 연속되지 않기 때문에 (3, 10, ...)
            // 위에서보다 계산 과정이 더 복잡하다.
            int temp_sum = sizes_by_color[i].front();
            smaller_color[i].push_back(0);
            for (int j = 1; j < sizes_by_color[i].size(); j++)
            {
                if (sizes_by_color[i][j - 1] == sizes_by_color[i][j])
                {
                    temp_sum += sizes_by_color[i][j];
                    smaller_color[i].push_back(smaller_color[i].back());
                }
                else
                {
                    smaller_color[i].push_back(smaller_color[i].back() + temp_sum);
                    temp_sum = sizes_by_color[i][j];
                }
            }
        }
    }
}

void solve()
{
    for (auto &b : balls)
    {
        auto [color, size] = b;
        int ans;
        // 1. 자기보다 작은 공의 크기의 합을 구한다
        ans = smaller_all[size];
        // 2. 자기보다 작은 공 중 자신과 색깔이 같은 공의 크기의 합을 구한다
        auto &same_color = sizes_by_color[color];
        auto begin_index = std::lower_bound(same_color.begin(), same_color.end(), size) - same_color.begin();
        int minus = smaller_color[color][begin_index];
        // 1에서 2를 빼면 정답
        ans -= minus;
        std::cout << ans << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, s;
        std::cin >> c >> s;
        balls.emplace_back(c, s);
    }
    preprocess();

    solve();
}