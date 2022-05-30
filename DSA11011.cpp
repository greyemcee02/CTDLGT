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
int n;

void makeNode(Node *root, int b, char c){
	if(c == 'L' && root->left == NULL)
		root->left = new Node(b);
	else if(c == 'R' && root->right == NULL)
		root->right = new Node(b);
}

void insert(Node *root, int a, int b, char c){
	if(root == NULL) return;
	if(root->data == a){
		makeNode(root, b, c);
	}
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}

bool travel(Node *root){
	if(root->left == NULL && root->right == NULL){
		return true;		
	}
	else if(root->left != NULL && root->right != NULL){
		if(!travel(root->left)) return false;
		if(!travel(root->right)) return false;
		return true;
	}
	else return false;
}

void solve(){
	cin >> n;
	int a, b;
	char c;
	Node *root = NULL;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root = new Node(a);
			makeNode(root, b, c);
		}
		else insert(root, a, b, c);
	}
	cout << travel(root) << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
