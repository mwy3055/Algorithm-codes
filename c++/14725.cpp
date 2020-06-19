#include <bits/stdc++.h>
using namespace std;

struct info
{
    int dep;
    vector<string> str;
    info(int dep) : dep(dep) {}
    bool operator<(const info &in)
    {
        int mindep = min(dep, in.dep);
        for (int i = 0; i < mindep; i++)
        {
            if (this->str[i] != in.str[i])
                return this->str[i] < in.str[i];
        }
        return this->dep < in.dep;
    }
};

int upper_bound(int dep, int s, int e, vector<info> &infos) // right bound of infos.str[dep]
{
    int cur = s;
    if (infos[cur].str.size() <= dep)
        return cur;
    string &target = infos[cur].str[dep];
    while (cur < e && dep < infos[cur].str.size() && infos[cur].str[dep] == target)
        cur++;
    return cur;
}

void printdash(int n)
{
    for (int i = 0; i < n; i++)
        cout << "--";
}
void print(int dep, int s, int e, vector<info> &infos) // [s, e)
{
    int cur = s;
    if (infos[cur].str.size() <= dep)
        return;
    while (cur < e)
    {
        int bound = upper_bound(dep, cur, e, infos);
        printdash(dep);
        cout << infos[cur].str[dep] << '\n';
        print(dep + 1, cur, bound, infos);
        cur = bound;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<info> infos;
    for (int a = 0; a < n; a++)
    {
        int k;
        cin >> k;
        info i(k);
        for (int j = 0; j < k; j++)
        {
            string s;
            cin >> s;
            i.str.push_back(s);
        }
        infos.push_back(i);
    }

    sort(infos.begin(), infos.end());
    print(0, 0, n, infos);
}