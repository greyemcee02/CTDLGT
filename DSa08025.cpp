#include<bits/stdc++.h>

using namespace std;
string str1, str2;

vector<pair<int, int>> dc = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

void BFS(){
	vector<vector<int>> Grid(9, vector<int>(9, INT_MAX));
	queue<pair<int, int>> Q;
	pair<int, int> ST = {str1[0] - 'a' + 1, str1[1] - '0'}, ED = {str2[0] - 'a' + 1, str2[1] - '0'};
	Q.push(ST);
	Grid[ST.first][ST.second] = 0;
	while(Grid[ED.first][ED.second] == INT_MAX && !Q.empty()){
		pair<int, int> pr = Q.front();
		Q.pop();
		for(auto it : dc){
			if(it.first + pr.first <= 8 && it.first + pr.first >= 1 
			&& it.second + pr.second <= 8 && it.second + pr.second >= 1){
				if(Grid[it.first + pr.first][it.second + pr.second] == INT_MAX){
					Grid[it.first + pr.first][it.second + pr.second] = Grid[pr.first][pr.second] + 1;
					Q.push({it.first + pr.first, it.second + pr.second});
				}
			}
		}
	}
	cout << Grid[ED.first][ED.second] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> str1 >> str2;
	BFS();
	}
	
	return 0;
}
