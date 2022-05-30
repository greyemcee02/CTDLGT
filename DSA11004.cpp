#include<bits/stdc++.h>

using namespace std;
int n;
struct Node{
	int data;
	Node *left, *right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

void makeNode(Node *root, int a, int b, char c){
	if(c == 'R') root->right = new Node(b);
	else if(c == 'L') root->left = new Node(b);
}

void insert(Node *root, int a, int b, char c){
	if(root == NULL) return ;
	if(root->data == a){
		makeNode(root, a, b, c);
	}
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}

void travel(Node *root){
	queue<Node *> Q;
	Q.push(root);
	while(!Q.empty()){
		Node *k = Q.front();
		Q.pop();
		cout << k->data << " ";
		if(k->left != NULL){
			Q.push(k->left);
		}
		if(k->right != NULL)
			Q.push(k->right);
	}
	cout << endl;
}

void solve(){
	cin >> n;
	int u, v;
	char c;
	Node *root = NULL;
	for(int i = 1; i <= n; i++){
		cin >> u >> v >> c;
		if(root == NULL){
			root = new Node(u);
			makeNode(root, u, v, c);		
		}
		else insert(root, u, v, c);
	}
	travel(root);
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
