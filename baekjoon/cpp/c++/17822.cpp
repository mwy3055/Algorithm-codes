#include <bits/stdc++.h>

using pii = std::pair<int, int>;

int n, m;
// pos[i]: i번 원판의 원점이 어디에 있는가?
int circle[50][50], pos[50];

// 회전된 상태에서 i번째 원판의 j번째 수를 반환
// j: 시계 방향으로 0, 1, ..., m - 1
int get(int i, int j)
{
    auto adj_pos = (j - pos[i] + m) % m;
    return circle[i][adj_pos];
}

void set(int i, int j, int val)
{
    auto adj_pos = (j - pos[i] + m) % m;
    circle[i][adj_pos] = val;
}

int get_idx(int j)
{
    return (j + m) % m;
}

// i번 원판을 d만큼 회전
// d > 0: 시계, d < 0: 반시계
void rotate_circle(int i, int d)
{
    pos[i] = (pos[i] + d + m) % m;
}

void rotate(int x, int d, int k)
{
    int real_k = k * (d ? -1 : 1);
    for (int c = x - 1; c < n; c += x)
        rotate_circle(c, real_k);
}

bool erase()
{
    bool result = false;
    std::vector<pii> erase_list;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            auto cur = get(i, j);
            if (cur == -1)
                continue;
            if (cur == get(i, get_idx(j - 1)))
            {
                result = true;
                erase_list.emplace_back(i, j);
                erase_list.emplace_back(i, get_idx(j - 1));
            }
            if (cur == get(i, get_idx(j + 1)))
            {
                result = true;
                erase_list.emplace_back(i, j);
                erase_list.emplace_back(i, get_idx(j + 1));
            }
            if (i > 0 && cur == get(i - 1, j))
            {
                result = true;
                erase_list.emplace_back(i, j);
                erase_list.emplace_back(i - 1, j);
            }
            if (i < n - 1 && cur == get(i + 1, j))
            {
                result = true;
                erase_list.emplace_back(i, j);
                erase_list.emplace_back(i + 1, j);
            }
        }
    }
    for (auto &e : erase_list)
    {
        auto [i, j] = e;
        set(i, j, -1);
    }
    return result;
}

double get_avg()
{
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            if ((val = get(i, j)) != -1)
            {
                sum += val;
                count++;
            }
        }
    }
    return (double)sum / count;
}

void erase_avg()
{
    auto avg = get_avg();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            auto val = get(i, j);
            if (val == -1)
                continue;
            if (val > avg)
            {
                set(i, j, val - 1);
            }
            else if (val < avg)
            {
                set(i, j, val + 1);
            }
        }
    }
}

void try_erase()
{
    auto result = erase();
    if (!result)
    {
        erase_avg();
    }
}

int get_sum()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = get(i, j);
            if (val != -1)
                sum += val;
        }
    }
    return sum;
}

void print()
{
    std::cout << "====================" << '\n';
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << get(i, j) << ' ';
        std::cout << '\n';
    }
    std::cout << "====================" << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> circle[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        int x, d, k;
        std::cin >> x >> d >> k;
        rotate(x, d, k);
        try_erase();
        // print(); // for debug
    }

    std::cout << get_sum() << '\n';
}