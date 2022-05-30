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
	if(c == 'L') root->left = new Node(b);
	else if(c == 'R') root->right = new Node(b);
}


void insert(Node *root, int a, int b, int c){
	if(root == NULL) return;
	if(root->data == a){
		makeNode(root, b, c);
	}	
	insert(root->left, a, b, c);
	insert(root->right, a, b, c);
}



void input(){
	int n;
	cin >> n;
	Node *root = NULL;
	set<int> st;
	int a, b;
	char c;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		if(root == NULL){
			root =  new Node(a);
			makeNode(root, b, c);
		}
		else insert(root, a, b, c);
		st.insert(a);
		st.insert(b);
	}	
	for(auto it: st)
		cout << it << " ";
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		cout << endl;	
	}
	return 0;
}
