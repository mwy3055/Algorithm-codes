#include <bits/stdc++.h>
using namespace std;
int fact(int n){
	int t=1;
	for(;n;n--) t*=n;
	return t;
}
int main(){
	int i, j, n, t, ans=0;
	cin >> n;
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-i;j++){
			t = n - i - j;
			if((j*1 + t*2) % 3 == 0){
				int h = fact(n), a = fact(i), b = fact(j), c = fact(t);
				h/=a*b*c;
				if(i) h -= fact(n-1)/(fact(i-1)*b*c);
				ans += h;
			}
		}
	}
	cout << ans;
	return 0;
}
