#include <bits/stdc++.h>

using apart = std::pair<int, int>; // pos, students

int n, k, s;
std::vector<apart> apartments;

void getinput()
{
    std::cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
    {
        int pos, num;
        std::cin >> pos >> num;
        apartments.emplace_back(pos, num);
    }
}

int search(std::vector<apart> &aparts)
{
    std::sort(aparts.begin(), aparts.end());
    int n = aparts.size();
    int ans = 0, fill = 0, max_diff = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        auto &[diff, students] = aparts[i];

        int total = fill + students;
        if (total < k)
        {
            // 계속 가면 됨
            max_diff = std::max(max_diff, diff);
            fill = total;
        }
        else if (total == k)
        {
            // 한번 털고 가자
            ans += (fill ? max_diff : diff) * 2;
            max_diff = 0;
            fill = 0;
        }
        else
        {
            // 이전에 타고 왔던 사람들
            if (fill > 0)
            {
                ans += max_diff * 2;
                total -= k;
            }

            // 여기서 최대한 태워 보내고
            int remainder = total % k;
            int shuttle = (total - remainder) / k;
            ans += diff * shuttle * 2;

            // 그래도 남은 사람들은 다음으로 넘김
            max_diff = (remainder ? diff : 0);
            fill = remainder;
        }
    }
    // 마지막에 남은 사람들
    if (fill)
        ans += max_diff * 2;
    return ans;
}

int solve()
{
    std::vector<apart> before, after;
    for (auto &[pos, num] : apartments)
    {
        if (pos < s)
        {
            before.emplace_back(s - pos, num);
        }
        else
        {
            after.emplace_back(pos - s, num);
        }
    }

    int ans1 = search(before);
    int ans2 = search(after);

    return ans1 + ans2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}