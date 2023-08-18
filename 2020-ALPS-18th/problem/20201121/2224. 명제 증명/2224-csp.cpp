#include <bits/stdc++.h>
using namespace std;
set<char> s, v[130];
vector<pair<char, char>> av;
int cnt;
void dfs(char c, bool (&visit)[130], set<char>& ans){
	for(auto it = v[c].begin(); it != v[c].end(); it++){
		if(visit[*it]) continue;
		ans.insert(*it);
		visit[c] = true;
		dfs(*it, visit, ans);
	}
	return;
}
void solve(char c){
	bool visit[130]={false};
	set<char> ans;
	visit[c] = true;
	dfs(c, visit, ans);
	cnt += ans.size();
	for(auto it = ans.begin(); it != ans.end(); it++) av.push_back({c, *it});
}
int main(){
	ios::sync_with_stdio(false), cin.tie(NULL);
	int i, j, n;
	char a, b;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a >> b >> b >> b;
		s.insert(a);
		s.insert(b);
		v[a].insert(b);
	}
	for (auto it = s.begin(); it != s.end(); it++) solve(*it);
	cout << cnt << "\n";
	for(auto it = av.begin(); it != av.end(); it++) cout << (*it).first << " => " << (*it).second << "\n";
}
