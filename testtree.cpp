#include<iostream>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};


class Tree{
	private:
		Node *root;
	public:
		Node *Make_Node();
		void Make_Root();
		void Insert_Left(Node *root, int value);
		void Insert_Right(Node *root, int value);
		void Remove_Left(Node *root, int value);
		void Remove_Right(Node *root, int valie);
		void Clear_Tree(Node *root);
		void NLR(Node *root);
		void LNR(Node *root);
		void LRN(Node *root);
		
};

Node *Tree::Make_Node(){
	Node *p = new Node;
	int tmp;
	cout << "Nhap gia tri cho node moi : ";
	cin >> tmp;
	p->data = tmp;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Tree::Make_Root() {
	if(root != NULL) {
		cout << "Da co node goc" << endl;
		return;
	}
	else{
		Node *p = Make_Node();
		root = p;
		p->left = NULL;
		p->right = NULL;
	}
}

void Tree::Insert_Left(Node *root, int value) {
	if(root != NULL) {
		if(root->data == value){
			if(root->left != NULL) {
				cout << "Node " << value << " da co node con trai" << endl;
				return;
			}
			else {
				Node *p = Make_Node();
				root->left = p;
				return;
			}
		}
		Insert_Left(root->left, value);
		Insert_Left(root->right, value);
	}
}

void Tree::Insert_Right(Node *root, int value) {
	if(root != NULL) {
		if(root->data == value) {
			if(root->right != NULL) {
				cout << "Node " << value << " da co node con phai" << endl;
				return;
			}
			else {
				Node *p = Make_Node();
				root->right = p;
				return;
			}
		}
		Insert_Right(root->left, value);
		Insert_Right(root->right, value);
	}
}

void Tree::Remove_Left(Node *root, int value) {
	if(root != NULL) {
		if(root->data == value) {
			if(root->left == NULL) {
				cout << "Node " << value << " khong co node con trai" << endl;
				return;
			}
			else if((root->left)->left != NULL || (root->left)->right != NULL) {
				cout << "Node " << value << " co cay con trai" << endl;
				return; 
			}
			else if((root->left)->left == NULL && (root->left)->right == NULL) {
				Node *p = root->left;
				root->left = NULL;
				delete(p);
				return;
			}	
		}
		Remove_Left(root->left, value);
		Remove_Left(root->right, value);
		
	}
}

void Tree::Remove_Right(Node *root, int value) {
	if(root != NULL) {
		if(root->data == value) {
			if(root->right == NULL) {
				cout << "Node " << value << " khong co node con phai" << endl;
				return;
			}
			else if((root->right)->left != NULL || (root->right)->right != NULL) {
				cout << "Node " << value << " co cay con phai" << endl;
				return; 
			}
			else if((root->right)->left == NULL && (root->right)->right == NULL) {
				Node *p = root->right;
				root->right = NULL;
				delete(p);
				return;
			}	
		}
		Remove_Right(root->left, value);
		Remove_Right(root->right, value);
	}
}

void Tree::Clear_Tree(Node *root) {
	if(root != NULL) {
		Clear_Tree(root->left);
		Clear_Tree(root->right);
		delete(root);
	}
}

void Tree::NLR(Node *root) {
	if(root != NULL) {
		cout << root->data << "   ";
		NLR(root->left);
		NLR(root->right);
	}
}

void Tree::LNR(Node *root) {
	if(root != NULL) {
		LNR(root->left);
		cout << root->data << "   ";
		LNR(root->right);
	}
}

void Tree::LRN(Node *root) {
	if(root != NULL) {
		LRN(root->left);
		LRN(root->right);
		cout << root->data << "   ";
	}
}
			p : 40
		p1 : 30   p2 : 42
		(24 < 40) p1 = in(p1, 24)
						24 < 30
						p3 = in(p3, 24);
							p3 = null tra ve x => p3 = x; tra ve p3
						
int main() {

	return 0;
}
