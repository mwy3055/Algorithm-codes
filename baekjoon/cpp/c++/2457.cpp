#include <bits/stdc++.h>

struct date
{
    int month, day;
    date(int month, int day) : month(month), day(day) {}

    bool operator<(const date &d) const
    {
        return month < d.month || (month == d.month && day < d.day);
    };
    bool operator>(const date &d) const
    {
        return month > d.month || (month == d.month && day > d.day);
    };
    bool operator==(const date &d) const
    {
        return month == d.month && day == d.day;
    };
    bool operator!=(const date &d) const
    {
        return !(*this == d);
    }
    bool operator<=(const date &d) const
    {
        return *this < d || *this == d;
    }
};

struct flower
{
    date start, end;
    flower(int m1, int d1, int m2, int d2) : start(m1, d1), end(m2, d2) {}

    bool operator<(const flower &other) const
    {
        if (start != other.start)
            return start < other.start;
        return end < other.end;
    }
};

std::vector<flower> flowers;

void getinput()
{
    int n;
    std::cin >> n;
    date start(3, 1), end(11, 30);
    for (int i = 0; i < n; i++)
    {
        int m1, d1, m2, d2;
        std::cin >> m1 >> d1 >> m2 >> d2;
        if (date(m2, d2) < start || date(m1, d1) > end)
            continue;
        flowers.emplace_back(flower(m1, d1, m2, d2));
    }
}

void print_flowers()
{
    std::cout << "===========================" << '\n';
    for (auto f : flowers)
        std::cout << f.start.month << ' ' << f.start.day << ' ' << f.end.month << ' ' << f.end.day << '\n';
    std::cout << "===========================" << '\n';
}

// 피는 날짜가 같은 꽃들: 지는 날짜가 가장 나중인 꽃만 남기기
void filter_flowers()
{
    int n = flowers.size();
    std::sort(flowers.begin(), flowers.end());

    std::vector<flower> temp;
    int index = 0;
    while (index < n)
    {
        auto start = flowers[index].start;
        while (index + 1 < n && start == flowers[index + 1].start)
            index++;
        temp.push_back(flowers[index++]);
    }
    flowers = temp;
}

// 3월 1일 전에 피는 꽃 중 가장 늦게 지는 꽃만 남기고 나머지는 지움
bool first_flower()
{
    int first = -1;

    auto max_end = date(-1, -1);
    int index = 0;
    while (index < flowers.size())
    {
        if (flowers[index].start > date(3, 1))
            break;
        else if (max_end < flowers[index].end)
        {
            max_end = flowers[index].end;
            first = index;
        }
        index++;
    }
    if (first == -1)
        return false;

    std::vector<flower> temp;
    temp.push_back(flowers[first]);
    for (int i = index; i < flowers.size(); i++)
        temp.push_back(flowers[i]);
    flowers = temp;
    return true;
}

int solve()
{
    filter_flowers();
    if (!first_flower())
        return 0;

    int ans = 1;
    int index = 0;
    auto [start, end] = flowers[index];
    while (index < flowers.size() - 1)
    {
        if (end > date(11, 30))
            break;
        auto max_end = end;
        // 구간이 끊어져 있다면 더 이상 탐색 불가
        bool consecutive = false;
        while (index + 1 < flowers.size() && flowers[index + 1].start <= end)
        {
            consecutive = true;
            if (max_end < flowers[index + 1].end)
            {
                max_end = flowers[index + 1].end;
            }
            index++;
        }
        if (!consecutive)
            break;
        end = max_end;
        ans++;
    }

    if (date(3, 1) < start || end <= date(11, 30))
        return 0;
    else
        return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}