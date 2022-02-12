#include <bits/stdc++.h>

int n;
std::vector<int> order;

bool visit[100001];
std::vector<int> graph[100001];
int parent[100001];
int child_count[100001];
int level[100001];
int level_count[100001];

void getinput()
{
    std::cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int ord;
        std::cin >> ord;
        order.push_back(ord);
    }
}

// 트리 만들기
void make_graph()
{
    std::queue<int> q;

    q.push(1);
    visit[1] = true;
    parent[1] = 0;
    child_count[0] = 1;
    int level_num = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int cur = q.front();
            q.pop();
            level[cur] = level_num;
            level_count[level_num]++;

            int child_num = 0;
            for (auto &adj : graph[cur])
            {
                if (!visit[adj])
                {
                    q.push(adj);
                    visit[adj] = true;
                    parent[adj] = cur;
                    child_num++;
                }
            }
            child_count[cur] = child_num;
        }
        level_num++;
    }
}

/**
 * 단순히 레벨이 같기만 하면 안 된다.
 * 부모가 나온 순서에 따라 자식이 나오는 순서가 결정되므로
 * 부모의 순서를 고려했을 때 현재 노드가 나올 수 있는지 확인해야 한다.
 */
int solve()
{
    // 바로 위 레벨의 부모, 현재 레벨의 노드
    std::vector<int> parents, current;

    parents.push_back(0);

    int cur_level = 1;
    int cur_count = 0;
    int parent_idx = 0;
    int parent_count = 0;
    for (auto &ord : order)
    {
        // 레벨이 다르거나 부모의 순서가 잘못되었다면
        if (level[ord] != cur_level || parent[ord] != parents[parent_idx])
        {
            return 0;
        }
        cur_count++;
        parent_count++;
        // 자식이 없는 노드는 부모로 고려할 필요가 없다.
        if (child_count[ord] != 0)
        {
            current.push_back(ord);
        }
        // 부모의 모든 자식을 탐색했다면 다음 부모로 이동
        if (parent_count == child_count[parents[parent_idx]])
        {
            parent_idx++;
            parent_count = 0;
        }
        // 현재 레벨을 모두 탐색했으면 다음 레벨로 이동
        if (cur_count == level_count[cur_level])
        {
            cur_level++;
            cur_count = 0;
            parent_idx = 0;
            parent_count = 0;
            parents = current;
            current.clear();
        }
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    make_graph();
    std::cout << solve() << '\n';
}