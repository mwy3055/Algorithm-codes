// Ʈ�� ���� Ʋ  
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
int n;
bool check[MAX + 1];
vector<pair<int, int>> node[MAX + 1];

int max_len;       //���� ����
int max_len_point; //������ �ش��ϴ� ����

void dfs(int point, int length)
{
    if (!check[point])
    {
        check[point] = true;
        //max_len �� max_len_point ����
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

    //���� �ָ� �ִ� ����(max_len_point) ���ϱ�
    dfs(1, 0);

    max_len = 0;

    memset(check, 0, sizeof(check));

    //max_len_point�� ���� �ָ� �ִ� �������� �Ÿ� ���ϱ�
    dfs(max_len_point, 0);
    cout << max_len << endl;

    return 0;
}
