const int MAX = 100000;

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

void union_vertex(int a, int b)
{
    int root1 = find(a), root2 = find(b);
    if (root1 == root2)
        return;

    if (root[root1] > root[root2])
        swap(root1, root2);

    root[root1] += root[root2];
    root[root2] = root1;
}