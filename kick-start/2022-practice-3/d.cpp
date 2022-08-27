#include <bits/stdc++.h>

int n, p;
std::vector<std::pair<int, int>> buses;
std::vector<int> queries;
int count[5001], begin[5001], end[5001];

void getinput()
{
    buses.clear();
    queries.clear();
    std::memset(count, 0, sizeof(count));
    std::memset(begin, 0, sizeof(begin));
    std::memset(end, 0, sizeof(end));

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        buses.emplace_back(a, b);
    }
    std::cin >> p;
    for (int i = 0; i < p; i++)
    {
        int c;
        std::cin >> c;
        queries.push_back(c);
    }
}

void preprocess()
{
    for (auto &[a, b] : buses)
    {
        begin[a]++;
        end[b]++;
    }

    for (int i = 1; i <= 5001; i++)
    {
        count[i] = count[i - 1] - end[i - 1] + begin[i];
    }
}

int solve(int city)
{
    return count[city];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; i++)
    {
        getinput();
        preprocess();
        std::cout << "Case #" << i << ": ";
        for (auto &query : queries)
        {
            int ans = solve(query);
            std::cout << ans << ' ';
        }
        std::cout << '\n';
    }
}