#include <bits/stdc++.h>

using ll = long long;

const int MAX = (1 << 21) - 1;

// i번을 루트로 하는 서브 트리에서 말단 가중치의 최댓값
// 말단 가중치: 루트에서 어떤 리프 노드까지의 가중치의 합
ll maxv[MAX];

int k, node_num; // 노드의 수
int leaf_start;  // 말단 노드의 시작 인덱스
// 가중치
int w[MAX];

void getinput()
{
    int parent = 0, child = 1;
    std::cin >> k;
    node_num = (1 << (k + 1)) - 1;
    leaf_start = (1 << k) - 1;
    for (int i = 0; i < node_num - 1; i++)
    {
        std::cin >> w[i];
    }
}

std::pair<int, int> edge_num(int parent)
{
    return std::make_pair(parent * 2, parent * 2 + 1);
}

// 자신을 루트로 하는 서브 트리에서 말단 가중치의 최댓값을 반환
ll search(int index)
{
    if (index >= leaf_start)
        return maxv[index] = 0;
    if (maxv[index] != -1)
        return maxv[index];

    auto [left_edge, right_edge] = edge_num(index);
    ll left_max = w[left_edge] + search(index * 2 + 1);
    ll right_max = w[right_edge] + search(index * 2 + 2);
    return maxv[index] = std::max(left_max, right_max);
}

// 자신을 루트로 하는 서브 트리에서 증가시킨 총 가중치를 반환
ll increment(int index, ll target)
{
    if (index >= leaf_start)
        return 0;

    auto [left_edge, right_edge] = edge_num(index);
    ll incr = 0;
    // 왼쪽
    ll left_max = w[left_edge] + search(index * 2 + 1);
    ll left_incr = target - left_max;
    incr += left_incr + increment(index * 2 + 1, target - w[left_edge] - left_incr);

    // 오른쪽
    ll right_max = w[right_edge] + search(index * 2 + 2);
    ll right_incr = target - right_max;
    incr += right_incr + increment(index * 2 + 2, target - w[right_edge] - right_incr);
    return incr;
}

ll solve()
{
    std::memset(maxv, -1, sizeof(ll) * MAX);
    ll max_w = search(0);

    // now increment
    ll incr_sum = increment(0, max_w);
    ll w_sum = 0;
    for (int i = 0; i < node_num - 1; i++)
    {
        w_sum += w[i];
    }
    return incr_sum + w_sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    std::cout << solve() << '\n';
}