#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define rep(i, a, b) for(lli i = (a); i < b; i++)
#define repa(i, a, b) for(lli i = (a); i >= b; i--)
int pos = 0;

struct TNodeData{
	lli x, ind;
};

struct TNode{
	TNode *left, *right;
	TNodeData data;
};

struct bst{

	TNode *root;

	bst(){
		root = nullptr;
	}

	void inorder()
	{
		__inorder(root);
	}

	void insert(TNodeData d){
		__insert(d, root);
	}

	void __insert(TNodeData &d, TNode *&t){
		if(t == nullptr){
			t = new TNode;
			t->data = d;
			return;
		}

		if(d.x < t->data.x) __insert(d, t->left);
		else __insert(d, t->right);
	}

	void __preorder(TNode *tr)
	{
		if( tr == NULL )
			return;

		cout << tr->data.x << " ";
		__preorder(tr->left);
		__preorder(tr->right);
	}

	void __inorder(TNode *tr)
	{
		if( tr == NULL )
			return;

		__inorder(tr->left);
		tr->data.ind = pos++;
		__inorder(tr->right);
	}

	void __posorder(TNode *tr)
	{
		if( tr == NULL )
			return;

		__posorder(tr->left);
		__posorder(tr->right);
		cout << tr->data.x << " ";
	}

	int find(TNodeData d){
		return __find(d, root);
	}

	int __find(TNodeData &d, TNode *node){
		if(node == nullptr) return -1;
		if(node->data.x == d.x) return node->data.ind;

		if(d.x < node->data.x) return __find(d, node->left);
		else return __find(d, node->right);
	}
};

int main() {

	std::cin.tie(nullptr);
  	std::ios_base::sync_with_stdio(false);
	
	bst arbol;
	
	return 0;
}
