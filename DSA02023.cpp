#include<bits/stdc++.h>

using namespace std;
int n, k, cnt;
vector<int> check;
void Try(int i, vector<string> str, vector<int> &check, vector<string> res) {
	for(int j = check[i - 1] + 1; j < n - k + i ; j++) {
		res.push_back(str[j]);
		check[i] = j;
		if(i == k){
			for(auto it : res)
				cout << it << " ";
			cout << endl;
		}
		else Try(i + 1, str, check, res);
		res.pop_back();
	}
}



int main() {
	cin >> n >> k;
	set<string> st;
	vector<string> str;
	vector<string> res;
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		st.insert(s);
	}
	check.push_back(-1);
	for(auto it : st){
		str.push_back(it);
		check.push_back(0);
	}
	n = str.size();
	Try(1, str, check, res);
	return 0;
}

