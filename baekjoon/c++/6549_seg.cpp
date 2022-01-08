#include <iostream>
using namespace std;
typedef pair<long, long> Pair; //ÃÖ¼Ú°ª, ³ÐÀÌ
typedef struct S
{
	int seg_s, seg_e;
	Pair val;
} Segment;
const int MAX_DEP = 18, MAX_IDENTITY = 0, MIN_IDENTITY = 0x7fffffff;
const int MAX = (1 << MAX_DEP) - 1;
int n;
Segment tree[MAX];
#define now tree[i]
inline long max(long a, long b) { return a < b ? b : a; }
inline long min(long a, long b) { return a < b ? a : b; }
Pair makeValue(int i)
{
	Segment& a = tree[2 * i + 1], &b = tree[2 * i + 2];

	long len = min(n, (a.seg_e - a.seg_s + 1) * 2), amin, rmin;
	if (a.val.first == 0 || b.val.first == 0)
		rmin = max(a.val.first, b.val.first);
	else
		rmin = min(a.val.first, b.val.first);

	if (a.val.first == MIN_IDENTITY && b.val.first == MIN_IDENTITY)
		amin = 0;
	else if (b.val.first == MIN_IDENTITY)
	{
		len /= 2;
		amin = a.val.first;
	}
	else
		amin = min(a.val.first, b.val.first);
	return Pair(rmin, max(max(a.val.second, b.val.second), amin*len));
}
void make_tree(int i, int n, int* arr)
{
	if ((1 << (MAX_DEP - 1)) - 1 <= i)
	{
		int idx = i - ((1 << (MAX_DEP - 1)) - 1);
		now.seg_s = now.seg_e = idx;
		if (idx < n)
			now.val = Pair(arr[idx], arr[idx]);
		else
			now.val = Pair(MIN_IDENTITY, MAX_IDENTITY);
	}
	else
	{
		make_tree(2 * i + 1, n, arr);
		make_tree(2 * i + 2, n, arr);
		now.seg_s = tree[2 * i + 1].seg_s, now.seg_e = tree[2 * i + 2].seg_e;
		now.val = makeValue(i);
	}
}

void print()
{
	for (int i = 0; i < MAX; i++)
	{
		if (tree[i].seg_e < n)
			cout << tree[i].seg_s << " " << tree[i].seg_e << " " << tree[i].val.second << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	while (n != 0)
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		make_tree(0, n, arr);
		delete[] arr;

		print();

		cout << tree[0].val.second << '\n';
		cin >> n;
	}
}