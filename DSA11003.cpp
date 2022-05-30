#include<bits/stdc++.h>

using namespace std;

int n;

int search(int in[], int val, int sz){
	for(int i = 0; i < sz ;i++){
		if(val == in[i]) return i;
	}
	return -1;
}

void postOrder(int in[], int pre[], int sz){
	int x = search(in, pre[0], sz);
	if(x != 0){
		postOrder(in, pre + 1, x);	
	}
	if(x != sz - 1){
		postOrder(in + x + 1, pre + x + 1, sz - x - 1);
	}
	cout << pre[0] << " ";
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		int pre[n], in[n];
		for(int i = 0; i < n; i++)
			cin >> in[i];
		for(int i = 0; i < n; i++)
			cin >> pre[i];
		postOrder(in, pre, n);
		cout << endl;
	}
	return 0;
}
