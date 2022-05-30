#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

int search(int in[], int x, int sz){
	for(int i = 0; i < sz; i++)
		if(x == in[i]) return i;
	return -1;
}

void post(Node *root, int inOrder[], int levelOrder[]){
	int x = search(levelOrder[0], sz);
	
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		int inOrder[n], levelOrder[n];
		for(int i = 0; i < n; i++)
			cin >> inOrder[i];
		for(int i = 0; i < n; i++)
			cin >> levelOrder[i];
		postOrder(inOrder, levelOrder[0], n);
		cout << endl;
	}	
	return 0;
}
