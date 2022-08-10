#include <iostream>

using ll = long long;

ll w, h, f, c, x1, y1, x2, y2;

void getinput()
{
    std::cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;
}

ll colored_horizontal()
{
    ll result = (x2 - x1) * (y2 - y1);
    // 두 번 접힌 영역의 오른쪽 끝.
    // 왼쪽 끝은 당연히 (0, 0)
    auto hx = std::min(f, w - f);
    if (x1 < hx)
    {
        // 두 번 접힌 곳
        result += (std::min(hx, x2) - x1) * (y2 - y1);
    }
    return result;
}

ll solve()
{
    ll colored_total = 0;
    colored_total = colored_horizontal();
    // 세로로 접은 횟수
    colored_total *= (c + 1);
    return w * h - colored_total;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}