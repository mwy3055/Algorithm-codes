#include <iostream>
using namespace std;

typedef struct node {
	char c;
	struct node *left, *right;
} node;

void preorder(node* n)
{
	cout << n->c;
	if (n->left != NULL)
		preorder(n->left);
	if (n->right != NULL)
		preorder(n->right);
}
void inorder(node* n)
{
	if (n->left != NULL)
		inorder(n->left);
	cout << n->c;
	if (n->right != NULL)
		inorder(n->right);
}
void postorder(node* n)
{
	if (n->left != NULL)
		postorder(n->left);
	if (n->right != NULL)
		postorder(n->right);
	cout << n->c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	node* tree = new node[n];
	for (int i = 0; i < n; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'].c = a;
		tree[a - 'A'].left = (b == '.' ? NULL : &tree[b - 'A']);
		tree[a - 'A'].right = (c == '.' ? NULL : &tree[c - 'A']);
	}

	preorder(tree);
	cout << '\n';
	inorder(tree);
	cout << '\n';
	postorder(tree);
	cout << '\n';



	delete[] tree;
}