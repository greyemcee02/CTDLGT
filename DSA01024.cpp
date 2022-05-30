#include<bits/stdc++.h>

using namespace std;
int n, k;
set<string> st;
vector<string> s;
void Try(int i, int a, vector<string> res){
	for(int j = a + 1; j <= n - k + i; j++){
		res.push_back(s[j - 1]);
		if(i == k){
			for(auto it : res)
				cout << it << " ";
			cout << endl;
		}
		else Try(i + 1, j, res);
		res.pop_back();
	}
}

int main() {
	cin >> n >> k;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		st.insert(str);
	}
	for(auto it : st)
		s.push_back(it);
	n = st.size();
	vector<string> res;
	Try(1, 0, res);
	return 0;
}
