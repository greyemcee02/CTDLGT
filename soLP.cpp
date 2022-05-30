

#include<iostream>
#include<string>

using namespace std;
int n;
vector<string> res;



void NP(string s){
	for(int j = 0; j <= 1; j++){
		if(!j){
			s.push_back('6');
		}
		else s.push_back(('8'));
		if(s.length() == n ) res.push_back(s);
		else NP(s);
		s.pop_back();
	}
}


int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		res.clear();
		NP("");
		cout << res.size() << endl;
		for(auto it : res)
			cout << it <<	" ";
		cout << endl;
	}
	return 0;
}
