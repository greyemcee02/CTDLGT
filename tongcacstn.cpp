#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<vector<int>> res;
void Try(int i, int s, vector<int> save){
	for(int j = i; j >= 1; j--){
		if(s + j <= n){
			s += j;
			save.push_back(j);
			if(s == n){
				res.push_back(save);
			}
			else Try(j, s, save);
			s-=j;
			save.pop_back();
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		res.clear();
		vector<int> save;
		Try(n, 0, save);
		cout << res.size() << endl;
		for(auto it : res){
			cout << "(";
			for(int j = 0; j <it.size() - 1; j++)
				cout << it[j] << " ";
			cout << it[it.size() - 1];
			cout << ") "; 
		}
		cout << endl;
	}
	return 0;
}
