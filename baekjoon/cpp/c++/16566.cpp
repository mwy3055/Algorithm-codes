// 배열에서 특정한 수보다 크면서 가장 작은 정수를 찾아야 함 (로그 시간 안에?)
#include <bits/stdc++.h>

const int MAX = 4000010;

int root[MAX + 1];

void init()
{
    for (int i = 0; i <= MAX; i++)
        root[i] = -1;
}

int find(int n)
{
    if (root[n] < 0)
        return n;
    return root[n] = find(root[n]);
}

// b를 a에 병합
void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;
    root[root2] = root1;
}

int n, m, k;
std::vector<int> cards;

// query보다 큰 카드 중 가장 작은 카드
int search(int query)
{
    // [l, r]
    int l = 0, r = m - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int parent = find(cards[mid]);
        if (query >= parent)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    init();

    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int card;
        std::cin >> card;
        cards.push_back(card);
    }
    std::sort(cards.begin(), cards.end());

    for (int i = 0; i < k; i++)
    {
        int query;
        std::cin >> query;
        int result = search(query);
        std::cout << cards[result] << '\n';
        // 값이 작아지는 방향으로 union (카드 제거)
        int next = result == 0 ? 0 : cards[result - 1];
        union_vertex(next, cards[result]);
    }
}