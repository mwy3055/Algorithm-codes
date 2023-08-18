#include <bits/stdc++.h>
using namespace std;
int max_points[330][330];
struct plane{
	int from, to, point;
	bool operator<(const plane& p){
		if(from != p.from) return from < p.from;
		else if(to != p.to) return to < p.to;
		return point < p.point;
	}
}planes[100010];
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	int i, j, n, m, k;
	cin >> n >> m >> k;
	for(i=0;i<k;i++) cin >> planes[i].from >> planes[i].to >> planes[i].point;
	sort(planes, planes+k);
	for(i=0;i<k;i++){
		int from = planes[i].from, to = planes[i].to, point = planes[i].point;
		if(from == 1) max_points[to][2] = max(max_points[to][2], point);
		else for(j=2;j<m;j++) if(max_points[from][j]) max_points[to][j+1] = max(max_points[to][j+1], max_points[from][j] + point);
	}
	cout << *max_element(max_points[n], max_points[n]+m+1);
}
