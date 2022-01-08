#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000; //임의의 MAX number

int n; //문제의 입력 변수
int arr[MAX+1]; // 배열 선언 
int dp[MAX+1];
int v[MAX+1];
// int ans; // 문제의 해답에 해당하는 변수 선언 
// int p;

//Test Case가 여러개인 경우 초기화 함수가 필요, 그렇지 않을 경우 필요x
// void initialize()
// {
//     ans = 0; //답의 초기화 
//     //배열의 초기화
//     memset(arr, false, sizeof(arr));
// }

//문제의 입력을 받는 함수 
void input()
{   
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
    }
}

//solution에 필요한 함수 구현하는 공간


// 위에서 구현한 함수들을 통해 문제를 직접적으로 풀어내는 함수
// 문제의 요구사항이 간단할 경우 함수를 모듈화하지 않고 solution 내부에서 함수를 구현해도 됨 

void go(int p) {
	// ? -> ? -> ... a[v[p]] -> a[p]
	// ---------------------
	//        go(v[p]);
	if (p == -1) {
		return;
	}
	go(v[p]);
	cout << arr[p] << ' ';
}


void solution()
{   
    for (int i = 0; i < n; i++) {
		dp[i] = 1;
		v[i] = -1;

		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				v[i] = j;
			}
		}
	}
	int ans = dp[0];
	int p = 0;

	for (int i = 0; i < n; i++) {
		if (ans < dp[i]) {
			ans = dp[i];
			p = i;
		}
	}

    cout << ans << '\n';
	go(p);
	cout << '\n'; //답을 출력

}

void solve()
{
    
    // initialize(); //초기화하고
    input(); //입력을 받고
    solution(); // 푼다

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
