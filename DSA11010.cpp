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
int n, H;

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

bool travel(Node *root, int h){
	if(root->left == NULL && root->right == NULL){
		if(H == INT_MAX)
			H = h;
		else if(H != h)
			return false;
		return true;		
	}
	else if(root->left != NULL && root->right != NULL){
		if(!travel(root->left, h + 1)) return false;
		if(!travel(root->right, h + 1)) return false;
		return true;
	}
	else return false;
}

void solve(){
	cin >> n;
	H = INT_MAX;
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
	if(travel(root, 1)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		solve();
	}
	return 0;
}
