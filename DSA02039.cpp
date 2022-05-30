#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> res;

void Try(int a, int sum, vector<int> save){
	for(int j = a; j >= 1; j--){
		sum += j;
		save.push_back(j);
		if(sum == n) res.push_back(save);
		else if(sum < n) Try(j, sum, save);
		sum -= j;
		save.pop_back();
	}
}

void out(){
	cout << res.size() << endl;
	for(auto it : res){
		cout << "(";
		for(int i = 0; i < it.size() - 1; i++)
			cout << it[i] << " ";
		cout << it[it.size() - 1] << ") ";
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;	
		res.clear();
		vector<int> save;
		Try(n, 0, save);
		out();
	}
	return 0;
}
