#include<bits/stdc++.h>

using namespace std;
vector<int> snt;
vector<int> check(301, 1);
int k, p, s, n;
vector<vector<int>> res;

void sang(){
	check[0] = 0;
	check[1] = 0;
	for(int i = 2; i <= sqrt(300); i++){
		if(check[i]){
			for(int j = i * 2; j <= 300; j += i){
				check[j] = 0;
			}
		}
	}
}

void Try(int i, vector<int> save, int sum) {
	for(int j = save[i - 1] + 1; j < n - k + i; j++){
		if(sum + snt[j] <= s){
			sum += snt[j];
			save[i] = j ;
			if(i == k){
				if(sum == s){
					vector<int> tmp(k);
					for(int x = 1; x <= k; x++){
						tmp[x - 1] = snt[save[x]];
					}
					res.push_back(tmp);
				}
			}
			else Try(i + 1, save, sum);
			sum -= snt[j];
		}
	}
}

void output(){
	cout << res.size() << endl;
	for(auto it : res){
		for(auto i : it){
			cout << i << " ";
		}
		cout << endl;
	}
}

int main() {
	sang();
	int test;
	cin >> test;
	while(test--){
		cin >> k >> p >> s;
		snt.clear();
		res.clear();
		for(int i = p + 1; i <= s; i++){
			if(check[i]) snt.push_back(i);
		}	
		n = snt.size();
		vector<int> save(k + 1);
		save[0] = -1;
		Try(1, save, 0);
		output();
	}
	return 0;
}
