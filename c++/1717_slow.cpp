#include <iostream>
using namespace std;
typedef struct node {
	int n;
	struct node* parent; //NULL:·çÆ®
} node;

void Union(int& a, int& b, node*& arr)
{
	node *pa = arr + a, *pb = arr + b;
	while (pa->parent) pa = pa->parent;
	while (pb->parent) pb = pb->parent;
	if (pa != pb)
	{
		if (pa->n < pb->n)
			pb->parent = pa;
		else
			pa->parent = pb;
	}
}
bool Find(int& a, int& b, node*& arr)
{
	node *pa = arr + a, *pb = arr + b;
	while (pa->parent) pa = pa->parent;
	while (pb->parent) pb = pb->parent;
	return pa == pb;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	node* arr = new node[n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = node({i, NULL});

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)
			Union(a, b, arr);
		else
			cout << (Find(a, b, arr) ? "YES" : "NO") << '\n';
	}
}