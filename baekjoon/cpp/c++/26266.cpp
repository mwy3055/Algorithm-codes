#include <bits/stdc++.h>

std::string s1, s2;
const int MOD = 26;

// i in [0, 25]
char itoc(int i)
{
    return 'A' + i - 1;
}

int ctoi(char c)
{
    return (int)(c - 'A');
}

void getinput()
{
    std::cin >> s1 >> s2;
}

std::string solve()
{
    auto len = s1.length();

    std::vector<int> v;
    for (int i = 0; i < len; i++)
    {
        v.push_back((ctoi(s2[i]) - ctoi(s1[i]) + MOD) % MOD);
    }

    // for (auto &vv : v)
    //     std::cout << vv << ' ';
    // std::cout << '\n';

    std::string ans;
    for (int i = 1; i <= len; i++)
    {
        if (len % i == 0)
        {
            bool is_ans = true;
            for (int j = i; j < len; j++)
            {
                if (v[j] != v[j % i])
                {
                    is_ans = false;
                    break;
                }
            }
            if (is_ans)
            {
                for (int j = 0; j < i; j++)
                {
                    auto mod = v[j] ? v[j] : 26;
                    ans.push_back(itoc(mod));
                }
                return ans;
            }
        }
    }

    exit(-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}