#include <iostream>
#include <algorithm>
using namespace std;

typedef struct S
{
	int seg_s, seg_e;
	int val;
} Segment;
typedef pair<int, int> Pair; //실력, 순위
const int MAX_DEP = 20, IDENTITY = 0;
const int MAX = (1 << MAX_DEP) - 1;
Segment tree[MAX];
Pair arr[500000];
bool compare(Pair a, Pair b)
{
	return a.second < b.second;
}
void make_tree(int i)
{
	Segment& now = tree[i];

	if ((1 << (MAX_DEP - 1)) - 1 <= i) //밑바닥: 개별 원소
	{
		int idx = i - (((MAX + 1) >> 1) - 1);
		now.seg_s = now.seg_e = idx;
	}
	else
	{
		make_tree(2 * i + 1);
		make_tree(2 * i + 2);
		now.seg_s = tree[2 * i + 1].seg_s, now.seg_e = tree[2 * i + 2].seg_e;
	}
}
void adjust_tree(int k) //k번째 수를 1 증가시켜야 함
{
/*	Segment& now = tree[i];
	int &s = now.seg_s, &e = now.seg_e;
	if (s == e)
	{
		now.val++;
		return;
	}

	if (k - s < e - k)
		adjust_tree(2 * i + 1, k);
	else
		adjust_tree(2 * i + 2, k);
	now.val++;*/
	int tidx = k + (1 << (MAX_DEP - 1)) - 1;
	while (tidx != 0)
	{
		tree[tidx].val++;
		tidx = (tidx - 1) / 2;
	}
	tree[tidx].val++;
}
int sum(int i, int s, int e) //[s, e] 구간의 합을 반환
{
	Segment& now = tree[i];
	if (e < now.seg_s || now.seg_e < s)
		return IDENTITY;
	else if (s <= now.seg_s && now.seg_e <= e)
		return now.val;
	else
		return sum(2 * i + 1, s, e) + sum(2 * i + 2, s, e);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	make_tree(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
		arr[i].first = i;
	sort(arr, arr + n, compare);

	for (int i = 0; i < n; i++)
	{
		cout << sum(0, arr[i].first + 1, n - 1) + 1 << '\n';
		adjust_tree(arr[i].first);
	}
}