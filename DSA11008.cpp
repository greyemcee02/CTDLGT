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

int res;
bool ok;

void makeNode(Node *root, int b, char c) {
	if(c == 'L' && root->left == NULL) root->left = new Node(b);
	else if(c == 'R' && root->right == NULL) root->right = new Node(b);
}

void insert(Node *root, int a, int b, char c){
	if(root == NULL) return;
	if(root->data == a){
		makeNode(root, b, c);
	}
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}

void travel(Node *root, int h){
	if(!ok) return;
	if(root->left == NULL && root->right == NULL){
		if(res == INT_MAX){
			res = h;
			return;
		}
		else if(res != h){
			ok = false;
			return;
		}
	}
	if(root->left != NULL){
		travel(root->left, h + 1);
	}
	if(root->right != NULL)
		travel(root->right, h + 1);
}

void solve(){
	int n;
	cin >> n;
	int a, b;
	char c;
	Node *root = NULL;
	ok = true;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root = new Node(a);
			makeNode(root, b, c);
		}
		else insert(root, a, b, c);
	}
	res = INT_MAX;
	travel(root, 1);
	if(ok) cout << 1 << endl;
	else cout << 0 << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
		
	}
	return 0;
}
