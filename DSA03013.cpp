#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2){
	return (p1.second > p2.second);
}

int solve(vector<pair<char, int>> vec , int D, string str){
	vector<int> check(str.length(), -1);
	for(auto it = vec.begin(); it != vec.end(); it++){
		int s = it->second;
		int j = 0;
		while(j < str.length() && check[j] != -1 ) j++;
		if(j == str.length()) return -1;
 		while(s > 0){
			if(j >= str.length()) return -1;
			s--;
			check[j] = 1;
			j += D;
		}
	}
	return 1;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		string str;
		int D;
		cin >> D >> str;
		vector<pair<char, int>> vec;
		vector<int> check(300, 0);
		for(int i = 0; i < str.length(); i++){
			check[str[i]]++;
		} 
		for(int i = 0; i < str.length(); i++){
			if(check[str[i]] > 0){
				vec.push_back({str[i], check[str[i]]});
				check[str[i]] = 0;
			}
		}
		sort(vec.begin(), vec.end(), cmp);
		cout << solve(vec, D, str) << endl;
	}
	return 0;
}
