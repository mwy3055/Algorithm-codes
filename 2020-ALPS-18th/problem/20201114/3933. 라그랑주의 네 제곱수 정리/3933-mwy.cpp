#include <bits/stdc++.h>

const int INF = 1 << 15;
int memoi[1 << 15];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 1; i * i <= INF; i++)
    {
        memoi[i * i]++;
        for (int j = i; i * i + j * j <= INF; j++)
        {
            memoi[i * i + j * j]++;
            for (int k = j; i * i + j * j + k * k <= INF; k++)
            {
                memoi[i * i + j * j + k * k]++;
                for (int l = k; i * i + j * j + k * k + l * l <= INF; l++)
                {
                    memoi[i * i + j * j + k * k + l * l]++;
                }
            }
        }
    }

    int n;
    std::cin >> n;
    while (n)
    {
        std::cout << memoi[n] << '\n';
        std::cin >> n;
    }
}