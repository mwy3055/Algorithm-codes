#include <bits/stdc++.h>

int findpair(int &s, int &n, std::vector<int> &weight, std::map<int, int> weightmap)
{
    std::vector<bool> visit(n, false);
    int rtn = 0;
    for (auto &w : weight)
    {
        if (weightmap[w] == 0)
            continue;
        weightmap[w]--;
        if (weightmap[s - w] > 0)
        {
            weightmap[s - w]--;
            rtn++;
        }
        else
        {
            weightmap[w]++;
        }
    }
    return rtn;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> weight(n), sum;
        std::map<int, int> weightmap;
        for (auto &w : weight)
        {
            std::cin >> w;
            weightmap[w]++;
        }
        std::sort(weight.begin(), weight.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                sum.push_back(weight[i] + weight[j]);
            }
        }
        std::sort(sum.begin(), sum.end());
        sum.erase(unique(sum.begin(), sum.end()), sum.end());

        int ans = 0;
        for (auto &s : sum)
        {
            int val = findpair(s, n, weight, weightmap);
            ans = std::max(ans, val);
            // std::cout << "if s = " << s << " -> pair " << val << '\n';
        }
        std::cout << ans << '\n';
    }
}