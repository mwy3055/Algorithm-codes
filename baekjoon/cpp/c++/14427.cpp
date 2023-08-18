#include <bits/stdc++.h>

int values[(1 << 17) + 10];

using ll = long long;

struct segment
{
    int left, right;
    long long val; // 인덱스
};

// 최솟값 세그먼트 트리 - 실제 값 대신 인덱스를 저장함
class SegmentTree
{
private:
    std::vector<segment> tree;
    ll getval(segment &left, segment &right)
    {
        return getval(left.val, right.val);
    }

    /**
     * 각각 왼쪽, 오른쪽 구간에서의 최솟값의 위치가 주어질 때
     * 더 작은 값의 위치를 반환한다.
     */
    ll getval(ll &lidx, ll &ridx)
    {
        auto lval = values[lidx];
        auto rval = values[ridx];
        if (lval <= rval)
            return lidx;
        else
            return ridx;
    }

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
    segment &init(int i)
    {
        auto &now = tree[i];
        if (OFFSET <= i)
        {
            int arr_idx = i - OFFSET;
            now.left = now.right = arr_idx;
            now.val = arr_idx;
        }
        else
        {
            auto &left = init(2 * i + 1);
            auto &right = init(2 * i + 2);
            now.left = left.left;
            now.right = right.right;
            now.val = getval(left, right);
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
        {
            auto lidx = get(2 * i + 1, s, e);
            auto ridx = get(2 * i + 2, s, e);
            return getval(lidx, ridx);
        }
    }

    /**
     * 세그먼트 트리를 업데이트한다.
     * 
     * i: 현재 인덱스
     * index: 바꿀 값의 위치
     * val: 바꿀 값
     */
    long long update(int i, int &index)
    {
        auto &now = tree[i];
        if (now.left == now.right || index < now.left || now.right < index)
            return now.val;
        else
        {
            auto lidx = update(2 * i + 1, index);
            auto ridx = update(2 * i + 2, index);
            return now.val = getval(lidx, ridx);
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::memset(values, 0x3f, sizeof(values));

    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll num;
        std::cin >> num;
        values[i] = num;
    }

    auto tree = SegmentTree(18, n + 1);
    tree.init(0);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        std::cin >> x;
        if (x == 1)
        {
            int i;
            ll v;
            std::cin >> i >> v;
            values[--i] = v;
            tree.update(0, i);
        }
        else
        {
            auto result = tree.get(0, 0, n - 1);
            std::cout << result + 1 << '\n';
        }
    }
}