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
int n, res;
map<int, Node *> mp;

void makeNode(Node *root, int b, char c){
	if(c == 'L' ){
		root->left = new Node(b);
		mp[b] = root->left;
	}
	else if(c == 'R' ){
		root->right = new Node(b);
		mp[b] = root->right;
	}		
}

void insert(Node *root, int b, char c){
	if(root != NULL){
		makeNode(root, b, c);
	}
}

void travel(Node *root, int ok){
	if(root == NULL) return;
	else if(root->left == NULL && root->right == NULL){
		if(ok) res += root->data;
		return;
	} 
	travel(root->left, 0);
	travel(root->right, 1);
}

void solve(){
	mp.clear();
	cin >> n;
	int a, b;
	char c;
	res = 0;
	Node *root = NULL;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root = new Node(a);
			mp[a] = root;
			makeNode(root, b, c);
		}
		else insert(mp[a], b, c);
	}
	travel(root, 0);
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
