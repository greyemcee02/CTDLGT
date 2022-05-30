#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

Node *insert(Node *root, int val){
	if(root == NULL) return new Node(val);
	if(root->data < val) 
		root->right = insert(root->right, val);
	else if(root->data > val)
		root->left = insert(root->left, val);
	return root;
}

void leafNode(Node *root, int &count){
	if(root->left == NULL && root->right == NULL){
		count++;
		return;
	}
	if(root->left!=NULL) leafNode(root->left, count);
	if(root->right != NULL) leafNode(root->right, count);
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
		int count = 0;
		leafNode(root, count);
		cout << n - count <<endl;
	}	
	return 0;
}
