#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
int n, m, ans, X[4]={0, 0, -1, 1}, Y[4] = {1, -1, 0, 0}, table[22][22];
bool check[100], visited[22][22];
void dfs(int x, int y, int cnt){
	for(int i=0;i<4;i++){
		int _x = x+X[i];
		int _y = y+Y[i];
		if(0 <= _x && _x < n && 0 <= _y && _y < m && !check[table[_x][_y]] && !visited[_x][_y]){
			check[table[_x][_y]] = visited[_x][_y] = true;
			dfs(_x, _y, cnt+1);
			check[table[_x][_y]] = visited[_x][_y] = false;
		}
	}
	ans = max(ans, cnt);
	return;
}
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	int i, j;
	char c;
	cin >> n >> m;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> c;
			table[i][j] = c;
		}
	}
	check[table[0][0]] = visited[0][0] = true;
	dfs(0, 0, 1);
	cout << ans;
	return 0;
}
