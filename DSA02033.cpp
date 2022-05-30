#include<bits/stdc++.h>

using namespace std;
int n;
vector<string> res;

void Try(int i, string str, vector<int> check){
	for(int j = 1; j <= n; j++){
		if(!check[j]){
			check[j] = 1;
			str.push_back((char)(j + '0'));
			if(i == n || (i >= 2 && abs(str[i-1] - str[i-2]) == 1)){
				if(abs(str[i-1] - str[i-2]) == 1){
				}
				else if(i == n)
					res.push_back(str);
			}
			else Try(i + 1, str, check);
			check[j] = 0;
			str.pop_back();
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n;
		vector<int> check(n + 1, 0);	
		res.clear();
		string str;
		Try(1, str, check);
		for(auto it : res)
			cout << it << endl; 
//		if(res.size() == 0)
//		cout << endl;
	}
	return 0;
}

