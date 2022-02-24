#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int r, c, k;
vector<vector<int>> arr(3, vector<int>(3));

void R()
{
    int msiz = 0;
    for (auto &column : arr)
    {
        map<int, int> m;
        for (auto &e : column)
        {
            if (e)
                m[e]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for (auto &p : m)
            pq.push(pii(p.second, p.first));
        column.clear();
        msiz = max(msiz, (int)pq.size() * 2);
        while (!pq.empty())
        {
            // push
            auto top = pq.top();
            pq.pop();
            column.push_back(top.second);
            column.push_back(top.first);
        }
    }

    for (auto &column : arr)
    {
        column.resize(msiz, 0);
    }
}
void transpose()
{
    vector<vector<int>> temp(arr[0].size(), vector<int>(arr.size(), 0));
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[0].size(); j++)
            temp[j][i] = arr[i][j];
    arr = temp;
}
void C()
{
    transpose();
    R();
    transpose();
}
void operate()
{
    if (arr.size() >= arr[0].size())
        R();
    else
        C();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> arr[i][j];
    r--, c--;

    int ans = 0;
    while (true)
    {
        if ((r < arr.size() && c < arr[r].size() && arr[r][c] == k) || 100 < ans)
            break;
        operate();
        ans++;
        /*
        for (auto &c : arr)
        {
            for (auto &e : c)
                cout << e << ' ';
            cout << '\n';
        }
        cout.flush();*/
    }
    cout << (ans <= 100 ? ans : -1);
}