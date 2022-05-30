#include<bits/stdc++.h>

using namespace std;
struct ele{
	int A[2][3];
	int cnt;
};

ele st, ed;
int res;

void input(){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++)
			cin >> st.A[i][j];
	}		
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++)
			cin >> ed.A[i][j];
	}	
	res = 0;
	st.cnt = 0;
	ed.cnt = 0;
}

ele rorL(ele curr){
//	ele curr = a;
	swap(curr.A[0][0], curr.A[0][1]);
	swap(curr.A[1][0], curr.A[1][1]);
	swap(curr.A[0][0], curr.A[1][1]);
	curr.cnt++;
	return curr;
}

ele rorR(ele curr){
	//ele curr = a;
	swap(curr.A[0][1], curr.A[0][2]);
	swap(curr.A[1][1], curr.A[1][2]);
	swap(curr.A[0][1], curr.A[1][2]);
	curr.cnt++;
	return curr;
}

bool check(ele curr){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++)
			if(ed.A[i][j] != curr.A[i][j]) return false;
	}
	return true;
}

void BFS(){
	queue<ele> Q;
	Q.push(st);
	while(1){
		ele curr = Q.front();
		Q.pop();
		ele l = rorL(curr);
		if(check(l)){
			cout << l.cnt << endl;
			return;
		}
		Q.push(l);
		ele r = rorR(curr);
		if(check(r)){
			cout << r.cnt << endl;
			return;
		}		
		Q.push(r);
	}
}



void solve(){
	if(check(st)) cout << 0 << endl;
	BFS();
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		solve();
	}
	
	return 0;
}

