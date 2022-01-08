
//���� ����ó�� �� ���ô� 
//��� �¼��� �������˶��� ������� ����! 
//dp[0]�� �������� ���� (�������� �پ����� ��) -> ���� ����� ���� ������

#include <bits/stdc++.h>

using namespace std;

const int MAX = 40;

int n, m;

int dp[MAX + 1]; //������ ���� 1~i�� ��ġ�ϴ� ����� ��

vector<int> cases;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> m;

    vector<int> vip(m+1);

    for (int i = 1; i <= m; i++)
    {
        // int tmp;
        // cin >> tmp;
        // vip.push_back(tmp);
        cin >> vip[i];
    }


    dp[0] = 1;

    dp[1] = 1;
    dp[2] = 2; // ���� �ڸ� �ٲ�ɱ�
               // d[3] = 3;
               // d[4] = 5;
               // d[5] = 8; // -> d[n] = d[n-1] + d[n-2] (��, n > 2)
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // if (n == m){

    //     cout << '1' << '\n';

    //     return 0;
    // }

    //�������� ���� �� 
    else if (m == 0)
    {
        cout << dp[n] << '\n';

        return 0;
    }

    else
    {
        int num = 1;

        //ù��° �¼����� ù��° ������ ���� ����� ��
        cases.push_back(dp[vip[1] - 1]);

        //n��° ���������� n+��° ������ ������ ����� ��
        while (num < m)
        {
            cases.push_back(dp[vip[num + 1] - vip[num] - 1]);
            num++;
        }

        //������ ���������� ������ �¼� ������ ����� ��
        cases.push_back(dp[n - vip[m]]);

        int result = 1;

        //�������� ��� ������ �������� ��� ����Ǽ��� ������� ���е� ������ ����Ǽ��� ���� ����

        for (auto &j : cases)
        {
            //����Ǽ� �� ������ Ȯ�� 
            // cout << j << '\n';
            result *= j;
        }

        cout << result << '\n';

        return 0;
    }
}
