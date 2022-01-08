#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
const int MAX = 100001;
bool cmp(pr a, pr b){
	if(a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	pr x[100010], y[100010];
	int i, n, a, b;
	long long ans=0;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a >> b;
		x[i].first = y[i].first = a;
		x[i].second = y[i].second = b;
	}
	sort(x, x+n);
	sort(y, y+n, cmp);
	for(i=0;i<n;i++){
		auto start_x = lower_bound(x, x+n, pr(x[i].first, 0));
		auto end_x = lower_bound(x, x+n, pr(x[i].first, MAX));
		long long x_range = end_x - start_x - 1;
		
		auto start_y = lower_bound(y, y+n, pr(0, x[i].second), cmp);
		auto end_y = lower_bound(y, y+n, pr(MAX, x[i].second), cmp);
		long long y_range = end_y - start_y - 1;

		ans += x_range * y_range;
	}
	cout << ans;
}
