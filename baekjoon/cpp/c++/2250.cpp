#include <bits/stdc++.h>
using namespace std;

struct node
{
    int left, right;
    node(int l = -1, int r = -1) : left(l), right(r) {}
};
int n, maxlevel, child[10001][2], column[10001], minl[10001], maxr[10001]; // child[i][0]: i번 노드의 왼쪽에 있는 모든 자식 노드의 수
vector<node> nodes;
bool visit[10001];

void bfs(int s)
{
    queue<int> q;

    q.push(s);
    visit[s] = true;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();

        int &l = nodes[top].left, &r = nodes[top].right;
        if (l != -1 && !visit[l])
        {
            q.push(l);
            visit[l] = true;
        }
        if (r != -1 && !visit[r])
        {
            q.push(r);
            visit[r] = true;
        }
    }
}
int getroot()
{
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!visit[i])
        {
            root = i;
            bfs(i);
        }
    }
    return root;
}

int search(int cur) // cur의 자식의 수를 반환
{
    if (cur == -1)
        return -1;
    child[cur][0] = search(nodes[cur].left) + 1;
    child[cur][1] = search(nodes[cur].right) + 1;
    return child[cur][0] + child[cur][1];
}
void draw(int index, int l, int r, int level) // [l, r]
{
    if (index == -1)
        return;
    int &lchild = child[index][0], &rchild = child[index][1];
    column[index] = l + lchild;
    minl[level] = min(minl[level], column[index]);
    maxr[level] = max(maxr[level], column[index]);

    maxlevel = max(maxlevel, level);
    draw(nodes[index].left, l, l + lchild - 1, level + 1);
    draw(nodes[index].right, l + lchild + 1, r, level + 1);
}

void init()
{
    memset(minl, 0x3f, sizeof(int) * 10001);
    memset(maxr, 0xff, sizeof(int) * 10001);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();

    cin >> n;
    nodes = vector<node>(n + 1);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].left = b, nodes[a].right = c;
    }

    int root = getroot();
    search(root);
    draw(root, 1, n, 1);

    int maxi = 1, maxwidth = 0;
    for (int i = 1; i <= maxlevel; i++)
    {
        if (maxwidth < maxr[i] - minl[i] + 1)
        {
            maxwidth = maxr[i] - minl[i] + 1;
            maxi = i;
        }
    }
    cout << maxi << ' ' << maxwidth;
}