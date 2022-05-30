#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node* insert(Node *root, int value){
	if(root == NULL){
		return new Node(value);
	}
	if(root->data < value)
		root->right = insert(root->right, value);
	else if(root->data > value){
		root->left = insert(root->left, value);
	}
	return root;
}

void preordered(Node *root){
	if(root == NULL) return;
	cout << root->data << " ";
	preordered(root->left);
	preordered(root->right);
}

void solve(){
	int n, x;
	cin >> n;
	Node *root = NULL;
	for(int i = 1; i <= n; i++){
		cin >> x;
		root = insert(root, x);
	}	
	preordered(root);
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		solve();
	}	
	return 0;
}
