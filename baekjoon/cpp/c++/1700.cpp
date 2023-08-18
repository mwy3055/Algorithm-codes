#include <bits/stdc++.h>

// lastidx[i][j]: i번째 전자제품이 j번 시점 이후(j 포함)에서 사용되는 첫 번째 시점
int n, k, name[100], lastidx[101][101];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(lastidx, 0x3f, sizeof(lastidx));

    std::cin >> n >> k;
    for (int i = 0; i < k; i++)
        std::cin >> name[i];

    for (int i = 1; i <= k; i++)
    {
        for (int j = k - 1; j >= 0; j--)
        {
            if (name[j] == i)
                lastidx[i][j] = j;
            else
                lastidx[i][j] = lastidx[i][j + 1];
        }
    }

    int ans = 0;
    std::set<int> multitap;
    for (int i = 0; i < k; i++)
    {
        auto &e = name[i];
        if (multitap.count(e))
            continue;
        else if (multitap.size() < n)
            multitap.insert(e);
        else
        {
            int maxtime = -2, max_e = -1;
            for (auto &elec : multitap)
            {
                if (maxtime < lastidx[elec][i])
                {
                    maxtime = lastidx[elec][i];
                    max_e = elec;
                }
            }
            multitap.erase(max_e);
            multitap.insert(e);
            ans++;
        }
    }
    std::cout << ans << '\n';
}