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

bool NLR(Node *root1, Node *root2){
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	else if(root1 != NULL && root2!=NULL){
		if(root1->data != root2->data) return false;
		if(!NLR(root1->left, root2->left)) return false;
		if(!NLR(root1->right, root2->right)) return false;
		return true;
	}
	else return false;
}

Node * input(){
	int n;
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
	return root;
}

void solve(){
	Node *root1 = input(), *root2 = input();
	cout << NLR(root1, root2) << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
