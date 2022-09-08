#include <bits/stdc++.h>

int n, sum;
std::vector<std::string> words;

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

void getinput()
{
    sum = 0;
    words.clear();
    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;
        words.push_back(s);
    }
}

void dfs(TrieNode *cur, int type_count, bool root = false)
{
    // 타이핑 횟수는 마지막에만 더한다.
    if (cur->end)
        sum += type_count;
    // 이 글자를 쳐야 하는가?
    if (cur->children.size() + cur->end + root > 1)
        type_count++;
    for (auto &child : cur->children)
        dfs(child, type_count);
}

double solve()
{
    Trie trie;
    for (auto &w : words)
        trie.insert(w);

    // dfs!
    dfs(trie.root, 0, true);
    return (double)sum / n;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cout.precision(2);
    while (std::cin >> n)
    {
        getinput();
        std::cout << std::fixed << solve() << '\n';
    }
}