// 트리 문제 틀  
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
int n;
bool check[MAX + 1];
vector<pair<int, int>> node[MAX + 1];

int max_len;       //지름 길이
int max_len_point; //지름에 해당하는 끝점

void dfs(int point, int length)
{
    if (!check[point])
    {
        check[point] = true;
        //max_len 과 max_len_point 갱신
        if (max_len < length)
        {
            max_len = length;
            max_len_point = point;
        }

        for (int i = 0; i < node[point].size(); i++)
        {
            dfs(node[point][i].first, length + node[point][i].second);
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int parent, child, length;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> parent >> child >> length;
        node[parent].push_back(make_pair(child, length));
        node[child].push_back(make_pair(parent, length));
    }

    //가장 멀리 있는 정점(max_len_point) 구하기
    dfs(1, 0);

    max_len = 0;

    memset(check, 0, sizeof(check));

    //max_len_point와 가장 멀리 있는 정점과의 거리 구하기
    dfs(max_len_point, 0);
    cout << max_len << endl;

    return 0;
}
