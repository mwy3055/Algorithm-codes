//������� ��������

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000; //������ MAX number
const int COUNT = 100;

using pii = pair<int, int>;

int t, k;                   //������ �Է� ���� t: ������ �ݾ� k: ������ ������
int dp[COUNT + 1][MAX + 1]; // i��° �������� �Ἥ j���� ���� �� �ִ� ����� ��
int ans;                    // ������ �ش信 �ش��ϴ� ���� ����

pii arr[COUNT + 1]; //pair int int�� ���� ��

//Test Case�� �������� ��� �ʱ�ȭ �Լ��� �ʿ�, �׷��� ���� ��� �ʿ�x
// void initialize()
// {
//     ans = 0; //���� �ʱ�ȭ

//     // k�� ���� �Է����� ���� �ʾҴ�, dp�� ������ solution ���ο��� �����ϴ� �ɷ� (Ʋ�� ����)
//     for (int i = 0; i <= k; i++)
//     {
//         dp[i][0] = 1;
//     }
// }

//������ �Է��� �޴� �Լ�
void input()
{
    cin >> t >> k;
    //t: ������ �ݾ� k: ������ ������

    int price, cnt;

    //���� ������ �������迭�� �Է��� �ޱ� ������ ������Ҵ�. �ȹ����� �� ����� �ȴ�.
    for (int i = 1; i <= k; i++)
    {
        cin >> price >> cnt;
        arr[i] = pii(price, cnt); // x�� ¥�� ���� y���� �ִ�.
    }
}

//solution�� �ʿ��� �Լ� �����ϴ� ����

// ������ ������ �Լ����� ���� ������ ���������� Ǯ��� �Լ�
// ������ �䱸������ ������ ��� �Լ��� ���ȭ���� �ʰ� solution ���ο��� �Լ��� �����ص� ��
void solution()
{
    //���������� ������ �ʿ�
    //ù��° ���ں��� ��������Ƿ�
    sort(arr + 1, arr + k + 1);

    for (int i = 0; i <= k; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= k; i++)
    {
        int cur_price = arr[i].first;
        int cur_cnt = arr[i].second;
        for (int j = 1; j <= t; j++)
        {
            //���� �ݾװ� �ݾ� ���̴� ����� ���� �������� ����
            if (j < cur_price)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            for (int k = 0; k <= cur_cnt; k++)
            {
                if (j - k * cur_price < 0)
                    continue;

                dp[i][j] += dp[i - 1][j - k * cur_price];
            }
        }
    }

    ans = dp[k][t];
}

void solve()
{
    // initialize(); //�ʱ�ȭ�ϰ�
    input(); //�Է��� �ް�
    solution();   // Ǭ��

    cout << ans << '\n'; //���� ���
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
