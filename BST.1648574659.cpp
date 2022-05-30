#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

class BST{
	private:
		Node *root;
	public:
		Node *new_Node(int value);
		Node *insert_Node(Node *root, int value);
		Node *delete_Node(Node *root, int value);
		Node *search(Node *root, int value);
		Node *min_Value(Node *root);
		void preorder(Node *root);
		void inorder(Node *root);
		void postorder(Node *root);
};

Node *BST::new_Node(int value) {
	Node *tmp = new Node();
	tmp->data = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

Node *BST::insert_Node(Node *root, int value) {
	if(root == NULL){
		return new_Node(value);
	}
	if(value < root->data){
		root->left = insert(root->left, value);
	}
	else{
		root->right = insert(root->right, value);
	}
	return root;
}

Node *BST::delete_Node(Node *root, int value) {
	if(root == NULL)
		return root;
	if(value < root->data) {
		root->left = delete_Node(root->left, value);
	}
	else if(value > root->data) {
		root->right = delete_Node(root->right, value);
	}
	else{
		if(root->left == NULL) {
			Node *tmp = root->right;
			delete(root);
			return tmp;
		}
		else if(root->right = NULL) {
			Node *tmp = root->left;
			delete(root);
			return tmp;
		}
		Node *tmp = min_Value(root->right);
		root->data = tmp->data;
		root->right = delete_Node(root->right, tmp->data);
	}
	return root;
}

Node *BST::min_Value(Node *root) {
	Node *tmp = root;
	while(tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp;
}

Node *BST::search(Node *root, int value) {
	if(root == NULL || root->data == value) return root;
	if(value < root->data){
		return search(root->left, value);
	}
	return search(root->right, value);
}
//40 30 24 20 15 22 27 26 29 60 70 65 62 68 90
void BST::preorder(Node *root) {
	if(root != NULL) {
		cout << root->data << endl;
		preorder(root->left);
		preorder(root->right);
	}
}


//15 20 22 24 26 27 29 30 50 60 62 65 68 70 90
void BST::inorder(Node *root) {
	if(root != NULL) {
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}
}

void BST::postorder(Node *root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << endl;
	}
}

int main() {
	
	return 0;
}
