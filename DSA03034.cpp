#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void nhap(vector<int> &nums, int n){
	for(int i = 0; i < n; i++)
		cin >> nums[i];
}

void solve(vector<int> Ni, vector<int> Mi, vector<int> Ki){
	int i = 0, j = 0, k = 0;
	vector<int> res;
	while(i < Ni.size() && j < Mi.size() && k < Ki.size()){
		if(Ni[i] < Mi[j]){
			i++;
		}
		else if(Ni[i] > Mi[j]){
			j++;
		}
		else{
			if(Ki[k] == Mi[j]){
				res.push_back(Mi[j]);
				i++;
				j++;
				k++;
			}
			else if(Ki[k] < Mi[j]) k++;
			else{
				i++;
				j++;
			}
		}
		
	}
	if(res.size() == 0) cout << "NO" << endl;
	else{
		for(auto it : res)
			cout << it << " ";
		cout << endl;
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> Ni(n), Mi(m), Ki(k);
		nhap(Ni, n);
		nhap(Mi, m);
		nhap(Ki, k);
		solve(Ni, Mi, Ki);
	}
	return 0;
}
