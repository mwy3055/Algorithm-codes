// ���� ������ �߸��о �ð����ȴ�. �Ѱ��� �ɰ��԰� ���� ���� �����̴�...


#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[31][31]; //�˾� i��, �ݰ�¥�� �˾� j�� �϶� ���ڿ��� �� ����� ��  

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int h = 0; h <= 30; h++){
        dp[0][h] = 1;
        //��� ����¥�� �˾��̸� ����Ǽ��� 1����
    }

    for(int w = 1; w <= 30; w++){
        for(int h = 0; h <= 30; h++){
            if(h == 0){
                dp[w][h] = dp[w-1][1];
                //����¥�� �˾��� ������ ū �˾��� �ɰ��԰� ���� �˾� �ϳ��� ����
            }
            else{
                dp[w][h] = dp[w-1][h+1] + dp[w][h-1];
                //ū �˾��� �ɰ� �԰� ����¥�� �˾��� ����� ��� + ���� ¥�� �˾��� �Դ� ��� 
            }
        }
    }


    while(true){
        cin >> n;

        if(n == 0)
            break;
        else{
            cout << dp[n-1][1] << '\n';
        }
        
    }

    return 0;
}
