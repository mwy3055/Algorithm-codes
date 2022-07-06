#include <bits/stdc++.h>

using vi = std::vector<int>;
using point = std::pair<double, double>; // x, y

const double BASE_ANGLE = 3.141592 / 4;
vi values;

bool is_ccw(point &a, point &b, point &c)
{
    auto result = (b.first - a.first) * (c.second - a.second) -
                  (b.second - a.second) * (c.first - a.first);
    return result > 0;
}

void getinput()
{
    for (int i = 0; i < 8; i++)
    {
        int value;
        std::cin >> value;
        values.push_back(value);
    }
}

bool check(vi &indices)
{
    // x축에서 반시계 방향으로 점을 놓는다.
    std::vector<point> points;
    for (int i = 0; i < 8; i++)
    {
        auto r = values[indices[i]];
        points.emplace_back(r * cos(BASE_ANGLE * i), r * sin(BASE_ANGLE * i));
    }

    for (int i = 0; i < 8; i++)
    {
        // i를 중심으로 하는 세 점이 반시게 방향인가?
        auto &a = points[(i + 7) % 8];
        auto &b = points[i];
        auto &c = points[(i + 1) % 8];
        if (!is_ccw(a, b, c))
            return false;
    }
    return true;
}

int solve()
{
    vi indices;
    for (int i = 0; i < 8; i++)
    {
        indices.push_back(i);
    }

    int ans = 0;
    do
    {
        ans += check(indices);
    } while (std::next_permutation(indices.begin(), indices.end()));
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}