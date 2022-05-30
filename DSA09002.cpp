#include<bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();
	vector<pair<int, int>> DSC;
	for(int i = 1; i <= N; i++){
		string str;
		getline(cin, str);
		int a;
		istringstream iss(str);
		while(iss >> a){
			if(a > i){
				DSC.push_back({i, a});
			}
		}
	}
	for(auto it : DSC)
		cout << it.first << " " << it.second << endl;
	return 0;
}
