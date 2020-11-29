#include <bits/stdc++.h>
using namespace std;
int root[1000010];
int Find(int n){
	if(root[n] == -1) return n;
	return root[n] = Find(root[n]);
}
void Union(int a, int b){
	int rA = Find(a);
	int rB = Find(b);
	if(rA != rB) root[rA] = rB;
	return;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	int i, n, m, w, a, b;
	cin >> n >> m;
	fill(root, root+n+1, -1);
	for(i=0;i<m;i++){
		cin >> w >> a >> b;
		if(!w) Union(a, b);
		else cout << (Find(a) == Find(b) ? "YES" : "NO") << "\n";
	}
	return 0;
}
