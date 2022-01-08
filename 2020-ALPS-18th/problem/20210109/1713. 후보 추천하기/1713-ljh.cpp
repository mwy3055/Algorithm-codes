//�л��� ��õ��
//�л��� ������ �Խõ� �ð�
// 2 1 4
// 3 1 4
// 3 5 4
// 3 5 6
// 2 5 6
// 2 7 6
//�����ϰ� ����

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
int n, rec_cnt;
int recommend[MAX + 1]; //��õ �� �迭

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    //���� Ʋ�� ������ ���� �ð�, �ش� ������ �л� ��ȣ
    vector<pair<int, int>> v(n, {0, 0});

    cin >> rec_cnt;

    for (int i = 0; i < rec_cnt; i++)
    {
        int snum;
        cin >> snum;
        recommend[snum]++;

        bool replace = true;

        for (int j = 0; j < n; j++)
        {
            //���ڰ� ������� ��
            if (v[j].second == 0)
            {
                v[j].second = snum;
                v[j].first = i;
                replace = false;
                break;
            }

            //�̹� ���ڿ� �ִ� ���
            else if (v[j].second == snum)
            {
                replace = false;
                break;
            }
        }

        //���� ����
        if (replace)
        {
            int idx = 0;
            for (int j = 1; j < n; j++)
            {
                //��õ���� ���� �� �������� ���
                if (recommend[v[j].second] == recommend[v[idx].second])
                {
                    //�ð��� ���� ������ ��
                    if (v[j].first < v[idx].first)
                    {
                        idx = j;
                    }
                }
                //��õ ���� ���� ��
                else if (recommend[v[j].second] < recommend[v[idx].second])
                {
                    idx = j;
                }
            }
            //�ʱ�ȭ
            recommend[v[idx].second] = 0;
            v[idx].first = i;
            v[idx].second = snum;
        }
    }

    vector<int> picture;
    for (int i = 0; i < n; i++)
    {
        picture.push_back(v[i].second);
    }

    sort(picture.begin(), picture.end());
    for (int i = 0; i < n; i++)
    {
        cout << picture[i] << ' ';
    }

    return 0;
}
