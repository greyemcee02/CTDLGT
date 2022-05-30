#include<bits/stdc++.h>

using namespace std;

int main() {
	ifstream ifs;
	ifs.open("MTK.in");
	int n;
	ifs >> n;
	int mtk[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			ifs >> mtk[i][j];
	}
	vector<vector<int>> dsc;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(mtk[i][j]){
				dsc.push_back({i + 1, j + 1});
			}
		}
	}
	for(auto it : dsc)
		cout << it[0] << " " << it[1] << endl;
	return 0;
}
