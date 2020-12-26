
#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 200000;
const int H_MAX = 500000;

int N_arr[N_MAX+1];
int cnt_arr[H_MAX+1];

int n, h;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h;

    for (int i = 1; i <= n; i++){
        cin >> N_arr[i];
    }

    for(int i = 1; i <= h; i++){
        for (int j = 1; j <= n; j++){
            if((j % 2) != 0){
                if(i <= N_arr[j]) cnt_arr[i]++;
            }
            else{
                if((h-i) <= (h- N_arr[j])) cnt_arr[i]++;
            }
        }
    }

    int min_cnt = 987654321;
    for(int i = 1; i <= h; i++){
        // cout << cnt_arr[i] << ' ';
        min_cnt = min(min_cnt, cnt_arr[i]);
    }

    // cout << min_cnt << '\n';

    int cnt = 0;

    for (int i =1; i <= h; i++){
        if(min_cnt == cnt_arr[i])
            cnt++;
    }

    cout << min_cnt << ' ' << cnt << '\n';
        
    return 0;
}
