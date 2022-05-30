#include<bits/stdc++.h>

using namespace std;

vector<int> SNT;

void sang() {
	vector<int> nt(10005, 1);
	nt[0] = 0;
	nt[1] = 0;
	int i = 4;
	for(int i = 4; i < 10005; i+= 2)
		nt[i] = 0;
	for(int i = 3; i < sqrt(10005); i++){
		if(nt[i]){
			for(int j = i*i; j < 10005; j+=i)
				nt[j] = 0;
		}
	}
	for(int i = 1000; i <= 9999; i++)
		if(nt[i]) SNT.push_back(i);
}

bool check(int num1, int num2){
	int cnt = 0;
	while(num1 > 0){
		int k1 = num1%10;
		int k2 = num2%10;
		if(k1 != k2) cnt++;
		if(cnt > 1) return false;
		num1 /= 10;
		num2 /= 10;
	}
	return true;
}

int solve(int S, int T){
	queue<pair<int, int>> Q;
	Q.push({S, 0});
	vector<int> vs(10005, 0);
	vs[S] = 1;
	while(!Q.empty()){
		int num = Q.front().first;
		int k = Q.front().second;
		Q.pop();
		if(num == T){
			return k;
		}
		for(auto it : SNT){
			if(!vs[it] && it != num &&check(num, it)){
			    if(it == T) return k + 1;
				Q.push({it, k + 1});
				vs[it] = 1;
			}
		}
	}
}

int main() {
	sang();
	int test;
	cin >> test;
	while(test--) {
		int S, T;
		cin >> S >> T;
		cout << solve(S, T) << endl;
	}
	return 0;
}
