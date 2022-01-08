#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000; //������ MAX number

int n; //������ �Է� ����
int arr[MAX+1]; // �迭 ���� 
int dp[MAX+1];
int v[MAX+1];
// int ans; // ������ �ش信 �ش��ϴ� ���� ���� 
// int p;

//Test Case�� �������� ��� �ʱ�ȭ �Լ��� �ʿ�, �׷��� ���� ��� �ʿ�x
// void initialize()
// {
//     ans = 0; //���� �ʱ�ȭ 
//     //�迭�� �ʱ�ȭ
//     memset(arr, false, sizeof(arr));
// }

//������ �Է��� �޴� �Լ� 
void input()
{   
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
    }
}

//solution�� �ʿ��� �Լ� �����ϴ� ����


// ������ ������ �Լ����� ���� ������ ���������� Ǯ��� �Լ�
// ������ �䱸������ ������ ��� �Լ��� ���ȭ���� �ʰ� solution ���ο��� �Լ��� �����ص� �� 

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
	cout << '\n'; //���� ���

}

void solve()
{
    
    // initialize(); //�ʱ�ȭ�ϰ�
    input(); //�Է��� �ް�
    solution(); // Ǭ��

}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
