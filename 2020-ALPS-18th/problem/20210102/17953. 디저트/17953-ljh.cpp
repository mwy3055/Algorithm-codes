#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[11][100001];
int dp[11][100001]; 
//dp[i][j] = i��° ����Ʈ��, j��° ���� �Ծ�����, �������� �ִ밪
 
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //���� ����
    for (int i = 1; i <= m; i++){
        dp[i][1] = arr[i][1];
    }

    //������ ���� 
    int max_cnt, temp;
    for (int j = 2; j <= n; j++)
    {
        for(int i = 1; i <= m; i++){
            max_cnt = -1;
            for(int k = 1; k <= m; k++){
                if (i == k) {temp = dp[k][j-1] + (arr[i][j])/2;} 
                //������ ���� ����Ʈ�� ������ ��
                else {temp = dp[k][j-1] + arr[i][j];}
                //������ �ٸ� ����Ʈ�� ������ �� 
                if(max_cnt < temp){
                    max_cnt = temp;
                    dp[i][j] = max_cnt;
                }
            }
        }
    }

    int max_result = -1;

    //ó�� ���ÿ� ���� ��� �� �ִ��� ��� 
    for(int i = 1; i <= m; i++){
        max_result = max(max_result, dp[i][n]);
    }

    cout << max_result << '\n';

    return 0;
}
