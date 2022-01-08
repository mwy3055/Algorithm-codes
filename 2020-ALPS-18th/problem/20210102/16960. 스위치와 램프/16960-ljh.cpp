#include <bits/stdc++.h>

const int MAX = 2000;
using namespace std;

int lamp[MAX + 1];
int n, m;
vector<int> Switch[MAX + 1];

bool switch_off(int idx)
{
    bool flag = true;
    //�Ѱ��� ������ 
    for (int i = 0; i < Switch[idx].size(); i++)
    {
        int x = Switch[idx][i];
        lamp[x]--;

        if (lamp[x] <= 0)
        {
            flag = false;
        }
    }

    //���� ����(�迭)���� �߱⿡ �ٽ� �ѳ���(�ǵ�����)
    for (int i = 0; i < Switch[idx].size(); i++)
    {
        int x = Switch[idx][i];
        lamp[x]++;
    }

    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int num;
            cin >> num;
            Switch[i].push_back(num);
            lamp[num]++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (switch_off(i) == true)
        {
            cout << '1' << '\n';
            return 0;
        }
    }
    cout << '0' << '\n';

    return 0;
}