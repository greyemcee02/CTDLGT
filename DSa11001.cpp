#include<bits/stdc++.h>

using namespace std;

struct Node{
	char data;
	Node *left, *right;
	Node(char x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

void LRN(Node *root){
	if(root == NULL) return;
	LRN(root->left);
	cout << root->data;
	LRN(root->right);
	
}

void solve(){
	string str;
	cin >> str;
	stack<Node *> stk;
	for(auto it: str){
		if(it == '+' || it == '-' || it == '*' || it =='/'){
			Node *r = stk.top();
			stk.pop();
			Node *l = stk.top();
			stk.pop();
			Node *k = new Node(it);
			k->left = l;
			k->right = r;
			stk.push(k);
		}
		else stk.push(new Node(it));
	}
	Node *root = stk.top();
	stk.pop();
	LRN(root);
	cout << endl;
}


int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
