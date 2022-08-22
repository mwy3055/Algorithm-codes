#include <bits/stdc++.h>

int n, x, y;
std::string s;
int parent[2001];
std::vector<int> child[2001], idx[2001]; // 0: total root

void getinput()
{
    std::cin >> n >> s >> x >> y;
}

void solve()
{
    if (x > y)
        std::swap(x, y);
    // 일단 트리를 만들자.
    int node_count = 0, current_node = 0, prev_node = 0;
    std::vector<int> target;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == '0')
        {
            child[current_node].push_back(++node_count);
            parent[node_count] = current_node;
            current_node = node_count;
            idx[current_node].push_back(i + 1);
            if (i + 1 == x || i + 1 == y)
                target.push_back(current_node);
        }
        else
        {
            if (i + 1 == x || i + 1 == y)
                target.push_back(current_node);
            idx[current_node].push_back(i + 1);
            current_node = parent[current_node];
        }
    }

    // 트리 완성, 이제 LCA를 구하자.
    // 우선 경로를 구하고
    std::stack<int> sx, sy;
    int cur = target[0];
    do
    {
        sx.push(cur);
        cur = parent[cur];
    } while (cur != 0);
    cur = target[1];
    do
    {
        sy.push(cur);
        cur = parent[cur];
    } while (cur != 0);

    // 루트에서 시작하는 경로에서 가장 마지막으로 같은 원소가 LCA다.
    int ans;
    while (!sx.empty() && !sy.empty() && sx.top() == sy.top())
    {
        ans = sx.top();
        sx.pop();
        sy.pop();
    }
    for (auto &i : idx[ans])
        std::cout << i << ' ';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}