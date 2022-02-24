#include <bits/stdc++.h>
using namespace std;

struct board
{
    int x, w, h, idx;
    bool visible = false;
};

class cmp
{
public:
    bool operator()(const board &a, const board &b) const
    {
        if (a.h != b.h)
            return a.h > b.h;
        if (a.x + a.w != b.x + b.w)
            return a.x + a.w > b.x + b.w;
        return a.x < b.x;
    }
} CMP;

vector<board> boards;
struct line // vertical line
{
    int x, type; // 1: begin of the board, 0: end of the board
    int idx;     // index of board
    bool operator<(const line &l) const
    {
        if (this->x != l.x)
            return this->x < l.x;
        if (this->type != l.type)
            return this->type > l.type;
        return CMP(boards[this->idx], boards[l.idx]);
    }
    bool operator>(const line &l) const
    {
        return !(*this < l);
    }
};

void solve(int &n, vector<board> &boards)
{
    vector<line> lines;
    for (int i = 0; i < n; i++)
    {
        auto &cur = boards[i];
        lines.push_back({cur.x, 1, i});
        lines.push_back({cur.x + cur.w, 0, i});
    }
    sort(lines.begin(), lines.end());

    set<board, cmp> visible, invisible; // sort by height
    for (int i = 0, j; i < lines.size(); i = j)
    {
        for (j = i; j < lines.size() && lines[i].x == lines[j].x; j++)
        {
            auto &src = lines[j];
            auto &b = boards[src.idx];
            if (src.type)
                invisible.insert(b);
            else
            {
                if (b.visible)
                    visible.erase(b);
                else
                    invisible.erase(b);
            }
        }
        if (invisible.empty())
            continue;
        if (!visible.empty() && (*visible.begin()).h >= (*invisible.begin()).h)
            continue;

        auto top = *invisible.begin();
        top.visible = boards[top.idx].visible = true;
        visible.insert(top);
        invisible.erase(invisible.begin());
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, idx = 0;
    cin >> n;
    boards.resize(n);
    for (auto &w : boards)
    {
        cin >> w.x >> w.w >> w.h;
        w.idx = idx++;
    }

    solve(n, boards);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (boards[i].visible)
            ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto &a : ans)
        cout << a + 1 << ' ';
}