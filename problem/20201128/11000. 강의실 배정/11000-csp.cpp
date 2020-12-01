#include <bits/stdc++.h>
using namespace std;
struct classes{
	int from, to;
	bool operator<(const classes& p){
		if(from != p.from) return from < p.from;
		return to < p.to;
	}
}times[200000];
int main(){
	ios::sync_with_stdio(false),cin.tie(NULL);
	int i, n;
	priority_queue<int, vector<int>, greater<>> pq;
	cin >> n;
	for(i=0;i<n;i++) cin >> times[i].from >> times[i].to;
	sort(times, times+n);
	pq.push(times[0].to);
	for(i=1;i<n;i++){
		if(pq.top() <= times[i].from) pq.pop();
        pq.push(times[i].to);
	}
	cout << pq.size();
	return 0;
}
