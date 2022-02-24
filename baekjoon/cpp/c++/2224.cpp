#include <bits/stdc++.h>

int getidx(char c)
{
    if ('A' <= c && c <= 'Z')
        return c - 'A';
    else
        return 26 + (c - 'a');
}

char getchr(int i)
{
    if (i < 26)
        return 'A' + i;
    else
        return 'a' + (i - 26);
}

const int INF = 0x3f3f3f3f;
int map[52][52];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    memset(map, 0x3f, sizeof(map));

    int n;
    std::cin >> n;
    std::string s;
    for (int i = 0; i < n; i++)
    {
        char a, b;
        std::cin >> a >> s >> b;
        map[getidx(a)][getidx(b)] = 1;
    }

    // Floyd-warshall
    for (int k = 0; k < 52; k++)
    {
        for (int i = 0; i < 52; i++)
        {
            for (int j = 0; j < 52; j++)
            {
                if (i != j && j != k && k != i)
                    map[i][j] = std::min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    std::vector<std::string> answers;
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (i != j && map[i][j] != INF)
            {
                std::ostringstream os;
                os << getchr(i) << " => " << getchr(j);
                answers.push_back(os.str());
            }
        }
    }

    std::cout << answers.size() << '\n';
    for (auto &ans : answers)
        std::cout << ans << '\n';
}