#include <bits/stdc++.h>

const int MAX = 4000000;

int n, m, k;
std::vector<int> cards;
bool exist[MAX + 1];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int card;
        std::cin >> card;
        cards.push_back(card);
        exist[card] = true;
    }
    std::sort(cards.begin(), cards.end());

    for (int i = 0; i < k; i++)
    {
        int query;
        std::cin >> query;
        auto index = std::upper_bound(cards.begin(), cards.end(), query);
        while (!exist[*index])
            index++;
        std::cout << *index << '\n';
        exist[*index] = false;
    }
}