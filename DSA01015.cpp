#include<bits/stdc++.h>

using namespace std;


int main() {
	vector<long long> save;
	save.push_back(9);
	for(int i = 0; i <= 2080; i++){
		save.push_back(save[i] * 10);
		save.push_back(save[i] * 10 + 9);
	}
	vector<long long> res(501);
	for(int i = 1; i <= 500; i++){
		for(auto it : save){
			if(it % i == 0){
				res[i] = it;
				break;
			}
		}
	}
	int test;
	cin >> test;
	while(test--){
		int n;
		cin >> n;
		cout << res[n] << endl;
	}
	return 0;
}


//162
//243
//324
//405
//486

