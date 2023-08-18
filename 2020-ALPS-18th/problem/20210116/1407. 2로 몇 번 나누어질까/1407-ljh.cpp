
#include <bits/stdc++.h>

using namespace std;

int n, m;

int can_divided_by_two(int num, int cnt){
    
    if (num % 2 != 0)
        return cnt;
    
    else{
        num /= 2;
        cnt *= 2;
        can_divided_by_two(num, cnt);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int sum = 0;

    int cnt;
    int result;
    for(int i = m; i >= n; i--){
        cnt = 1;
        result = can_divided_by_two(i, cnt);
        cout << result << '\n';

        sum += result;
    }

    cout << sum  << '\n';

    return 0;
}
