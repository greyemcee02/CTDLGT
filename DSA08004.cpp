#include<bits/stdc++.h>

using namespace std;
int k;
string str;

long long solve(){
	priority_queue<long long> pq;
	vector<int> count(500, 0);
	for(int i = 0; i < str.length(); i++){
		count[str[i]]++;
	}
	for(int i = 0; i < 500; i++){
		if(count[i] > 0)
			pq.push(count[i]);
	}
	int x;
	while(k--){
		x = pq.top();
		pq.pop();
		if(x-1 > 0)
		pq.push(x-1);
	}
	long long res = 0;
	while(!pq.empty()){
		res += (long long)pq.top()* pq.top();
		pq.pop();
	}
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> k >> str;
		cout << solve() << endl;
	}
	return 0;
}
