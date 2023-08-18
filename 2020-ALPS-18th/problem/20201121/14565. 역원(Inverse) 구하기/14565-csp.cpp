#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll xGCD(ll n, ll a){
	int i;
	vector<ll> s{1, 0}, t{0, 1}, r{n, a}, q{0, 0};
	for(i=1;r.back()!=0;i++){
		q.push_back(r[i-1] / r[i]);
		r.push_back(r[i-1] % r[i]);
		s.push_back(s[i-1] - s[i] * q.back());
		t.push_back(t[i-1] - t[i] * q.back());
	}
	if(r[i-1] == 1) return (t[i-1] + n) % n;
	else return -1;
}
int main(){
	ll n, a, b;
	cin >> n >> a;
	b = xGCD(n, a);
	cout << n-a << " " << b;
}
