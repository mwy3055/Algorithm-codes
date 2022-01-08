#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
long long x[100010], y[100010], ans;
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	pr p[100010];
	int i, n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> p[i].first >> p[i].second;
		x[p[i].first]++;
		y[p[i].second]++;
	}
	for(i=0;i<n;i++) ans += (x[p[i].first]-1)*(y[p[i].second]-1);
	cout << ans;
}
