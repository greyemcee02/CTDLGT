#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	int st, ed;
	Node *left;
	Node *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

Node * insert(Node *root, int val, int c){
	if(c == 0){
		root->left = new Node(val);
		return root->left;
	} 
	else{
		root->right = new Node(val);
		return root->right;
	} 
	
}

int search(int inOrder[], Node *root){
	//cout << "------" << endl;
	//cout << root->data << " " << root->st << " " << root->ed << endl;
	for(int i = root->st; i <= root->ed; i++){
		if(inOrder[i] == root->data) return i;
	}
	return -1;
}

void travel(Node *root){
	if(root == NULL) return;
	travel(root->left);
	travel(root->right);
	cout << root->data << " ";
}

void postOrder(int inOrder[], int levelOrder[], int sz){
	int idx = 0;
	Node *root = new Node(levelOrder[0]);
	root->st = 0;
	root->ed = sz - 1;
	queue<Node *> Q;
	Q.push(root);
	while(!Q.empty()){
		Node *nd = Q.front();
		Q.pop();
		int x = search(inOrder, nd);
		if(x > nd->st ){
			idx++;
			Node *l = insert(nd, levelOrder[idx], 0);
			l->st = nd->st;
			l->ed = x - 1;
			Q.push(l);
		}
		if(x < nd->ed){
			idx++;
			Node *r = insert(nd, levelOrder[idx], 1);
			r->st = x + 1;
			r->ed = nd->ed;
			Q.push(r);
		}
	}
	travel(root);
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		int inOrder[n], levelOrder[n];
		for(int i = 0; i < n; i++)
			cin >> inOrder[i];
		for(int i = 0; i < n; i++)
			cin >> levelOrder[i];
		
		postOrder(inOrder, levelOrder, n);
		cout << endl;
	}	
	return 0;
}

