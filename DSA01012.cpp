#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	int test;
	cin >> test;
	while(test--){
		vector<string> res;
		cin >> n;
		res.push_back("0");
		res.push_back("1");
		for(int i = 0; i < n - 1; i++) {
			vector<string> tmp;
			for(int j = 0; j < res.size(); j++){
				tmp.push_back("0" + res[j]);
			}
			for(int j = res.size() - 1; j >= 0; j--){
				tmp.push_back("1" + res[j]);
			}
			res = tmp;
		}
		for(auto it : res)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
