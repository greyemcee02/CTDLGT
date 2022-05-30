#include<bits/stdc++.h>

using namespace std;
struct Node {
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};


Node * insert(Node *root, int val){
	if(root == NULL){
		return new Node(val);
	}
	if(root->data < val){
		root->right = insert(root->right, val);
	}
	else if(root->data > val){
		root->left = insert(root->left, val);	
	}
	return root;
}

void post(Node *root){
	if(root == NULL) return;
	post(root->left);
	post(root->right);
	cout << root->data << " ";
	
}


int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		Node *root = NULL;
		int x;
		for(int i = 0; i < n; i++){
			cin >> x;
			root = insert(root, x);
		}
		post(root);
		cout << endl;
		
	}
	return 0;
}
