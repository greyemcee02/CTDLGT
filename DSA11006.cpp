#include<bits/stdc++.h>

using namespace std;
struct Node{
	int data;
	Node *left, *right;
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void makeNode(Node *root, int b, char c){
	if(c == 'L' && root->left == NULL) root->left = new Node(b);
	else if(c == 'R' && root->right == NULL) root->right = new Node(b);
}

void insert(Node *root, int a, int b, char c){
	if(root == NULL) return;
	if(root->data == a) makeNode(root, b, c);
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);	 
}

void solve(Node *root){
	bool ok = false;
	stack<Node *> stk;
	stk.push(root);
	while(1){
		stack<Node *> tmp;
		while(!stk.empty()){
			cout << stk.top()->data << " ";
			if(ok){
				if(stk.top()->left != NULL)
					tmp.push(stk.top()->left);
				if(stk.top()->right != NULL)
					tmp.push(stk.top()->right);
			}
			else{
				if(stk.top()->right != NULL)	
					tmp.push(stk.top()->right);
				if(stk.top()->left != NULL)
					tmp.push(stk.top()->left);
			}
			stk.pop();
		}
		ok = !ok;
		if(tmp.empty()) return;
		stk = tmp;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
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
		solve(root);
		cout << endl;
	}
	return 0;
}
