#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data, height;
	Node *left, *right;
	Node(int val, int h){
		data = val;
		height = h;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node *root, int val){
	if(root == NULL){
		return new Node(val, 0);
	}
	if(root->data < val ){
		root->right = insert(root->right, val);
		root->height = max(root->height, root->right->height + 1);
	}
	else if(root->data > val){
		root->left = insert(root->left, val);
		root->height = max(root->height, root->left->height + 1);
	}
	return root;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, x;
		cin >> n;
		Node *root = NULL;
		for(int i = 1; i <= n; i++){
			cin >> x;
			root = insert(root, x);
		}
		cout << root->height << endl;
	}
	return 0;
}
