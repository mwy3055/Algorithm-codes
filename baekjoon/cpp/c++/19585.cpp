#include <bits/stdc++.h>

class TrieNode
{
public:
    int children[26];
    bool end;
    TrieNode(bool end = false) : end(end) {}
    void insert(int child_idx, char c)
    {
        children[c - 'a'] = child_idx;
    }
};

class Trie
{
public:
    TrieNode nodes[1001 * 4001];
    int size;
    Trie()
    {
        size = 0;
    }
    void insert(std::string &s)
    {
        auto cur = 0;
        for (auto &c : s)
        {
            auto next = find(cur, c);
            if (next == 0)
            {
                nodes[cur].insert(++size, c);
                cur = size;
            }
            else
            {
                cur = next;
            }
        }
        nodes[cur].end = true;
    }
    int find(int cur, char c)
    {
        return nodes[cur].children[c - 'a'];
    }
    bool contains(std::string s)
    {
        auto cur = 0;
        for (auto &c : s)
        {
            auto next = find(cur, c);
            if (next == 0)
            {
                return false;
            }
            cur = next;
        }
        return nodes[cur].end;
    }
};

int c, n, cmax, nmax;
Trie color_trie, nickname_trie;

void getinput()
{
    std::cin >> c >> n;
    for (int i = 0; i < c; i++)
    {
        std::string color;
        std::cin >> color;
        if (cmax < color.size())
            cmax = color.size();
        color_trie.insert(color);
    }
    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name;
        if (nmax < name.size())
            nmax = name.size();
        std::reverse(name.begin(), name.end());
        nickname_trie.insert(name);
    }
}

bool check_contains(std::string &team)
{
    std::vector<bool> front(team.size(), false), back(team.size(), false);
    auto color_idx = 0;
    for (int i = 0; i < team.size(); i++)
    {
        auto color_next = color_trie.find(color_idx, team[i]);
        if (color_next == 0)
            break;
        color_idx = color_next;
        if (color_trie.nodes[color_idx].end)
            front[i] = true;
    }

    auto name_idx = 0;
    for (int i = team.size() - 1; i >= 0; i--)
    {
        auto name_next = nickname_trie.find(name_idx, team[i]);
        if (name_next == 0)
            break;
        name_idx = name_next;
        if (nickname_trie.nodes[name_idx].end)
            back[i] = true;
    }

    for (int i = 0; i < team.size() - 1; i++)
    {
        if (front[i] && back[i + 1])
            return true;
    }
    return false;
}

void solve()
{
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        std::string team;
        std::cin >> team;
        bool ans = false;
        // 색깔은 그대로, 닉네임은 뒤집어서 넣음
        if (team.size() <= cmax + nmax)
        {
            ans = check_contains(team);
        }
        std::cout << (ans ? "Yes" : "No") << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    getinput();
    solve();
}