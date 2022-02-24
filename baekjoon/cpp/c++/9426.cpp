#include <bits/stdc++.h>

struct segment
{
    int left, right;
    long long val;
};

// 특정 구간에 정수 i가 몇 개나 있는가?
class SegmentTree
{
private:
    std::vector<segment> tree;

public:
    const int MAX_DEP, IDENTITY, MAX; // n <= 2^(MAX_DEP - 1)
    const int OFFSET;
    SegmentTree(int max_dep, int identity) : MAX_DEP(max_dep), IDENTITY(identity), MAX((1 << MAX_DEP) - 1), OFFSET((1 << (MAX_DEP - 1)) - 1)
    {
        tree.resize(MAX);
    }

    /**
     * 세그먼트 트리를 value로 초기화한다.
     * 
     * i: 현재 인덱스
     * value: 초기화할 값
     */
    segment &init(int i, const long long value)
    {
        auto &now = tree[i];
        if (OFFSET <= i)
        {
            int arr_idx = i - OFFSET;
            now.left = now.right = arr_idx;
            now.val = value;
        }
        else
        {
            auto &left = init(2 * i + 1, value);
            auto &right = init(2 * i + 2, value);
            now.left = left.left;
            now.right = right.right;
            now.val = left.val + right.val;
        }
        return now;
    }

    /**
     * q번째 값을 구한다.
     * 
     * i: 현재 인덱스
     * q: q번째 값
     */
    long long get(int i, int q)
    {
        if (OFFSET <= i)
            return i - OFFSET;
        auto &left = tree[2 * i + 1];
        if (left.val >= q)
            return get(2 * i + 1, q);
        else
            return get(2 * i + 2, q - left.val);
    }

    /**
     * 특정 위치의 값을 1 증가시킨다.
     * 
     * i: 현재 인덱스
     * index: 값을 증가시킬 위치
     */
    long long increase(int i, int &index)
    {
        auto &now = tree[i];
        if (now.left == index && now.right == index)
            return ++now.val;
        else if (now.left == now.right || index < now.left || now.right < index)
            return now.val;
        else
            return now.val = increase(2 * i + 1, index) + increase(2 * i + 2, index);
    }

    /**
     * 특정 위치의 값을 1 감소시킨다.
     * 
     * i: 현재 인덱스
     * index: 값을 감소시킬 위치
     */
    long long decrease(int i, int &index)
    {
        auto &now = tree[i];
        if (now.left == index && now.right == index)
            return --now.val;
        else if (now.left == now.right || index < now.left || now.right < index)
            return now.val;
        else
            return now.val = decrease(2 * i + 1, index) + decrease(2 * i + 2, index);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    SegmentTree tree(17, 0);
    tree.init(0, 0);

    for (int i = 0; i < k - 1; i++)
    {
        tree.increase(0, numbers[i]);
    }

    int mid = (k + 1) / 2;
    long long ans = 0;
    for (int i = k - 1; i < n; i++)
    {
        tree.increase(0, numbers[i]);
        auto midval = tree.get(0, mid);
        ans += midval;
        tree.decrease(0, numbers[i - k + 1]);
    }
    std::cout << ans << '\n';
}