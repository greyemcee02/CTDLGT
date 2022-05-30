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
vector<Node *> par;
void makeNode(Node *root, int b, char c){
	if(c == 'L' && root->left == NULL){
		root->left = new Node(b);
	}	
	else if(c == 'R' && root->right == NULL){
		root->right = new Node(b);
	}	
}

void find(Node *root, Node *p, int a, int b, char c){
	if(root == NULL) return;
	if(root->data == a && root->right == NULL){
		p = root;
	}
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}


void rightLeafNode(Node *root){
	queue<Node *> Q;
	Q.push(root);
	int res = 0;
	while(!Q.empty()){
		Node *p = Q.front();
		Q.pop();
		if(p->left != NULL) Q.push(p->left);
		if(p->right != NULL){
			if(p->right->left!= NULL || p->right->right!= NULL){
				Q.push(p->right);
			}
			else res += p->right->data;
		}
	}
	cout << res << endl;
}

void solve(){
	cin >> n;
	int a, b;
	char c;
	par.resize(10001, NULL);
	Node *root = NULL;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root = new Node(a);
			par[a] = root;
			makeNode(root, b, c);
		}
		else{
			Node *p = NULL;
			find(root, p, a, b, c);
			if(p != NULL){
				
			}
		} 
	}
	rightLeafNode(root);
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
