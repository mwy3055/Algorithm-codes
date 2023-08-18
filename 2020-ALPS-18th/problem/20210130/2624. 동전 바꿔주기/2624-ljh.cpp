// 어려웠던 동전문제

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000; // 임의의 MAX number
const int COUNT = 100;

using pii = pair<int, int>;

int t, k;                   // 문제의 입력 변수 t: 지폐의 금액 k: 동전의 가지수
int dp[COUNT + 1][MAX + 1]; // i번째 동전까지 써서 j원을 만들 수 있는 경우의 수
int ans;                    // 문제의 해답에 해당하는 변수 선언

pii arr[COUNT + 1]; // pair int int의 약자 ㅎ

// Test Case가 여러개인 경우 초기화 함수가 필요, 그렇지 않을 경우 필요x
//  void initialize()
//  {
//      ans = 0; //답의 초기화

//     // k를 아직 입력으로 받지 않았다, dp에 기저는 solution 내부에서 수행하는 걸로 (틀린 원인)
//     for (int i = 0; i <= k; i++)
//     {
//         dp[i][0] = 1;
//     }
// }

// 문제의 입력을 받는 함수
void input()
{
    cin >> t >> k;
    // t: 지폐의 금액 k: 동전의 가지수

    int price, cnt;

    // 많은 문제가 이차원배열의 입력을 받기 때문에 살려놓았다. 안받으면 뭐 지우면 된다.
    for (int i = 1; i <= k; i++)
    {
        cin >> price >> cnt;
        arr[i] = pii(price, cnt); // x원 짜리 동전 y개가 있다.
    }
}

// solution에 필요한 함수 구현하는 공간

// 위에서 구현한 함수들을 통해 문제를 직접적으로 풀어내는 함수
// 문제의 요구사항이 간단할 경우 함수를 모듈화하지 않고 solution 내부에서 함수를 구현해도 됨
void solution()
{
    // 오름차순의 정렬이 필요
    // 첫번째 인자부터 사용했으므로
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
            // 동전 금액과 금액 사이는 경우의 수가 증가하지 않음
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
    // initialize(); //초기화하고
    input();    // 입력을 받고
    solution(); // 푼다

    cout << ans << '\n'; // 답을 출력
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
