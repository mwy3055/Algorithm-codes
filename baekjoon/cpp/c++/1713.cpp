#include <bits/stdc++.h>

struct vote
{
    int count, uptime;
    vote(int c = 0, int u = -1) : count(c), uptime(u) {}
};

int get_remove(std::vector<vote> &votes)
{
    int min_cnt = 10000, min_time = -1, min_idx = -1;
    for (int i = 1; i <= 100; i++)
    {
        auto &v = votes[i];
        if (v.count == 0)
            continue;
        if (v.count == min_cnt && v.uptime < min_time)
        {
            min_idx = i;
            min_time = v.uptime;
        }
        else if (v.count < min_cnt)
        {
            min_idx = i;
            min_time = v.uptime;
            min_cnt = v.count;
        }
    }
    return min_idx;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<vote> votes(101);

    int size = 0;
    for (int i = 0; i < m; i++)
    {
        int r;
        std::cin >> r;
        auto &v = votes[r];
        if (v.count != 0)
            v.count++;
        else if (size < n)
        {
            v.count++;
            v.uptime = i;
            size++;
        }
        else
        {
            // remove a picture
            auto remove_idx = get_remove(votes);
            auto &remove = votes[remove_idx];
            remove.count = 0;
            // insert
            v.count++;
            v.uptime = i;
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        if (votes[i].count != 0)
            std::cout << i << ' ';
    }
}