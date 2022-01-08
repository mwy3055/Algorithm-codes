#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pr;
int n;
vector<pr> v;
bool solved, check[90][11];
int table[10][10];

void bt(int now) {
	int i, j;
	if (now == v.size()) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) cout << table[i][j];
			cout << endl;
		}
		solved = true;
		return;
	}
	if (!solved) {
		for (i = v[now].first / 3 * 3; i < v[now].first / 3 * 3 + 3; i++) {
			for (j = v[now].second / 3 * 3; j < v[now].second / 3 * 3 + 3; j++) {
				if (table[i][j] != 0) check[now][table[i][j]] = true;
			}
		}
		for (i = 0; i < 9; i++) check[now][table[v[now].first][i]] = check[now][table[i][v[now].second]] = true;

		for (i = 1; i <= 9; i++) {
			if (check[now][i]) continue;
			table[v[now].first][v[now].second] = i;
			check[now][i] = true;
			bt(now + 1);
			if (solved) break;
			table[v[now].first][v[now].second] = 0;
			check[now][i] = false;
		}

		for (i = 1; i <= 9; i++) check[now][i] = false;
	}
}
int main() {
	int i, j;
	char c;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			cin >> c;
            table[i][j] = c-48;
			if (table[i][j] == 0) v.push_back(pr(i, j));
		}
	}
	bt(0);
	return 0;
}
