#include<bits/stdc++.h>

using namespace std;
struct Node{
	int value;
	int s;
	Node *left, *right;
	Node(int val){
		value = val;
		left = NULL;
		right = NULL;
	}
};
int res;

void makeNode(Node *root, int b, int c){
	if(c == 'L') root->left = new Node(b);
	else if(c == 'R') root->right = new Node(b);
}

void insert(Node *root, int a, int b, char c){
	if(root == NULL) return;
	if(root->value == a){
		makeNode(root, b, c);
		return;
	}
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}

void travel(Node *root){
	if(root == NULL) return;
	travel(root->left);
	travel(root->right);
	if(root->left != NULL && root->right != NULL){
		res = max(res, root->left->s + root->right->s + root->value);
		root->s = root->value + max(root->left->s, root->right->s);
	}
	else if(root->left == NULL && root->right == NULL){
		root->s = root->value;
		return;
	}
	else if(root->left == NULL){
		root->s = root->value + root->right->s;
	}
	else{
		root->s = root->value + root->left->s;
	}
}

void solve(){
	int n;
	cin >> n;
	Node *root = NULL;
	int a, b;
	char c;
	res = INT_MIN;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root = new Node(a);
			makeNode(root, b, c);
		}
		else insert(root, a, b, c);
	}
	travel(root);
	cout << res << endl;
}


int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	
	return 0;
}
