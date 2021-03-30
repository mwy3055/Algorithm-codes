// 배열에서 특정한 수보다 크면서 가장 작은 정수를 찾아야 함 (로그 시간 안에?)
#include <bits/stdc++.h>

int n, m, k;
std::set<int> cards;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int card;
        std::cin >> card;
        cards.insert(card);
    }

    for (int i = 0; i < k; i++)
    {
        int query;
        std::cin >> query;
        auto it = cards.upper_bound(query);
        std::cout << *it << '\n';
        cards.erase(it);
    }
}