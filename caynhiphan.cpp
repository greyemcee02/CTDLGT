#include<bits/stdc++.h>

using namespace std;

struct Node{
	int infor;
	Node *left, *right;
	
	Node(int data){
		infor = data;
		left = NULL;
		right = NULL;
	}
};


void makeNode(Node *root, int n1, int n2, char c){
	switch(c){
		case 'L':
			root->left = new Node(n2);
			break;
		case 'R':
			root->right = new Node(n2);
			break;
	}
}

void insert(Node *root, int n1, int n2, char c){
	if(root== NULL) return;
	if(root->infor == n1)
		makeNode(root, n1, n2, c);
	else{
		insert(root->left, n1, n2, c);
		insert(root->right, n1, n2, c);
	}
}

void travel(Node *root){
	if(root == NULL) return;
	cout << root->infor << " ";
	travel(root->left);
	travel(root->right);
}


int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		Node *root = NULL;
		while(n--){
			int n1, n2;
			char c;
			cin >> n1 >> n2 >> c;
			if(root == NULL){
				root = new Node(n1);
				insert(root, n1, n2, c);
			}
			else{
				insert(root, n1, n2, c);
			}
		}
	}	
	return 0;
}
