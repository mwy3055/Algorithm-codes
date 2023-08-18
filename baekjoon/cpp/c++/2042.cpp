#include <bits/stdc++.h>

struct segment
{
    int left, right;
    long long val;
};

// 예시: 합 세그먼트 트리
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
     * 세그먼트 트리를 초기화한다.
     * 주의: 사용할 트리의 종류에 따라 operation을 수정해야 한다.
     * 
     * i: 현재 인덱스
     * arr: 초기 배열
     */
    segment &init(int i, std::vector<long long> &arr)
    {
        auto &now = tree[i];
        if (OFFSET <= i)
        {
            int arr_idx = i - OFFSET;
            now.left = now.right = arr_idx;
            if (arr_idx < arr.size())
                now.val = arr[arr_idx];
            else
                now.val = IDENTITY;
        }
        else
        {
            auto &left = init(2 * i + 1, arr);
            auto &right = init(2 * i + 2, arr);
            now.left = left.left;
            now.right = right.right;
            now.val = left.val + right.val;
        }
        return now;
    }

    /**
     * 주어진 구간에 대해 세그먼트 트리의 값을 구한다.
     * 
     * i: 현재 인덱스
     * s: 구간의 왼쪽 끝 (inclusive)
     * e: 구간의 오른쪽 끝 (inclusive)
     */
    long long get(int i, int s, int e)
    {
        auto &now = tree[i];
        if (e < now.left || now.right < s)
            return IDENTITY;
        else if (s <= now.left && now.right <= e)
            return now.val;
        else
            return get(2 * i + 1, s, e) + get(2 * i + 2, s, e);
    }

    /**
     * 세그먼트 트리를 업데이트한다.
     * 
     * i: 현재 인덱스
     * index: 바꿀 값의 위치
     * val: 바꿀 값
     */
    long long update(int i, int &index, long long &val)
    {
        auto &now = tree[i];
        if (now.left == index && now.right == index)
            return now.val = val;
        else if (now.left == now.right || index < now.left || now.right < index)
            return now.val;
        else
            return now.val = update(2 * i + 1, index, val) + update(2 * i + 2, index, val);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<long long> arr;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        arr.push_back(num);
    }

    SegmentTree tree(21, 0);
    tree.init(0, arr);

    for (int i = 0; i < m + k; i++)
    {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        if (a == 1)
        {
            tree.update(0, --b, c);
        }
        else
        {
            auto result = tree.get(0, --b, --c);
            std::cout << result << '\n';
        }
    }
}