#include<bits/stdc++.h>

using namespace std;
int n, w, tmp;
long long fopt = 0;
vector<int> xopt;
void Try(vector<int> x, vector<int> ai, vector<int> ci, int i, long long bi, long long value) {
	for(int j = 1; j >= 0; j--) {
		if(bi + ai[i]*j <= w){
			bi += ai[i]*j;
			value += ci[i]*j;
			x[i] = j;
			if(i == n - 1) {
				if(value > fopt){
					fopt = value;
					xopt.clear();
					for(int k = 0; k < n; k++)
						xopt.push_back(x[k]);
				}
			}
			else Try(x, ai, ci, i + 1, bi, value);
			x.pop_back();
			bi -= ai[i]*j;
			value -= ci[i]*j;
		}
	}
}



int main() {
	cin >> n >> w;
	vector<int> ai(n), ci(n), x(n, 0);
	for(int i = 0; i < n; i++){
		cin >> ci[i];
	}
	for(int i = 0; i < n; i++){
		cin >> ai[i];
	}
	Try(x, ai, ci, 0, 0, 0);
	cout << fopt << endl;
	for(auto it : xopt)
		cout << it << " ";
	cout << endl;
	return 0;
}

