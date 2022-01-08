#include <bits/stdc++.h>

int prefix_pos[16][16], dp[16][1 << 16], track[16][1 << 16];
std::vector<std::string> no_dup;

int get_prefix_pos(std::string &str, std::string &query) // str의 뒷부분과 query의 앞부분이 겹치는 길이
{
    for (int len = std::min(str.size(), query.size()); len > 0; len--)
    {
        if (str.substr(str.size() - len) == query.substr(0, len))
            return len;
    }
    return 0;
}

void calculate_prefix_pos(std::vector<std::string> &s)
{
    for (auto i = 0; i < s.size(); i++)
    {
        for (auto j = 0; j < s.size(); j++)
        {
            if (i != j)
                prefix_pos[i][j] = get_prefix_pos(s[i], s[j]);
        }
    }
}

int get_max_overlap(int last, int used)
{
    auto &ret = dp[last][used];
    if (used == (1 << no_dup.size()) - 1)
        return ret = 0;
    if (ret != -1)
        return ret;
    for (auto next = 0; next < no_dup.size(); next++)
    {
        if ((used & (1 << next)) == 0)
        {
            auto temp = prefix_pos[last][next] + get_max_overlap(next, used | (1 << next));
            if (ret < temp)
            {
                ret = temp;
                track[last][used] = next;
            }
        }
    }
    return ret;
}

std::string solve()
{
    // 가장 많이 겹치는 시작 단어 찾기
    int max_first = 0, max_overlap = -1;
    for (auto i = 0; i < no_dup.size(); i++)
    {
        auto temp = get_max_overlap(i, 1 << i);
        if (max_overlap < temp)
        {
            max_overlap = temp;
            max_first = i;
        }
    }

    // 문자열 복원
    int cur = max_first, used = 1 << max_first;
    std::string ans = no_dup[cur];
    while (used != (1 << no_dup.size()) - 1)
    {
        int next = track[cur][used];
        auto &nextstr = no_dup[next];
        ans.append(no_dup[next].substr(prefix_pos[cur][next]));
        cur = next;
        used |= 1 << next;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int c;
    std::cin >> c;
    while (c--)
    {
        memset(dp, -1, sizeof(dp));
        memset(track, -1, sizeof(track));
        memset(prefix_pos, 0, sizeof(prefix_pos));
        no_dup.clear();

        int k;
        std::cin >> k;
        std::vector<std::string> strs;
        for (int i = 0; i < k; i++)
        {
            std::string s;
            std::cin >> s;
            strs.push_back(s);
        }
        // 전처리: 부분 문자열은 버림
        std::sort(strs.begin(), strs.end(), [](std::string &a, std::string &b) {
            return a.length() > b.length();
        });
        int bitmask = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (i != j && strs[i].find(strs[j]) != std::string::npos)
                {
                    bitmask |= (1 << j);
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            if ((bitmask & (1 << i)) == 0)
                no_dup.push_back(strs[i]);
        }
        // 문자열끼리 겹치는 길이 계산
        calculate_prefix_pos(no_dup);
        // 정답
        std::cout << solve() << '\n';
    }
}