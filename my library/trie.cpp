class TrieNode
{
public:
    std::vector<TrieNode *> children;
    char c;
    bool end;
    TrieNode(char c = '\0', bool end = false) : c(c), end(end)
    {
    }
    void insert(TrieNode *new_child)
    {
        children.push_back(new_child);
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(std::string &s)
    {
        auto cur = root;
        for (int i = 0; i < s.size(); i++)
        {
            auto next = find(cur, s[i]);
            if (next == nullptr)
            {
                auto new_node = new TrieNode(s[i]);
                cur->insert(new_node);
                cur = new_node;
            }
            else
            {
                cur = next;
            }
        }
        cur->end = true;
    }
    TrieNode *find(TrieNode *cur, char c)
    {
        for (auto &child : cur->children)
        {
            if (child->c == c)
                return child;
        }
        return nullptr;
    }
    ~Trie()
    {
        std::queue<TrieNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto &child : top->children)
            {
                q.push(child);
            }
            delete top;
        }
    }
};
