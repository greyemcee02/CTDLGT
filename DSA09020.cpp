#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	vector<vector<int>> MTK(n+1, vector<int>(n+1, 0));
	string dsk;
	for(int i = 1; i <= n; i++){
		getline(cin, dsk);
		istringstream iss(dsk);
		int v;
		while(iss >> v){
			MTK[i][v] = 1;
			MTK[v][i] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			cout << MTK[i][j] << " ";
		cout << endl;
	}	
	return 0;
}
