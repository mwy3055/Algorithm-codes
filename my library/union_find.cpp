class UnionFind
{
private:
    int size;
    std::vector<int> root;

public:
    UnionFind(int size) : size(size)
    {
        root.resize(size + 1, -1);
    }
    int find(int n)
    {
        if (root[n] < 0)
            return n;
        return root[n] = find(root[n]);
    }
    void merge(int a, int b)
    {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        if (root1 > root2)
            std::swap(root1, root2);
        root[root1] += root[root2];
        root[root2] = root1;
    }
};