#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int s1, s2, f1, f2;

struct C{
	int h, c, cnt;
};

vector<pair<int, int>> F = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int BFS(){
	queue<C> Q;
	Q.push({s1, s2, 0});
	vector<vector<int>> vs(9, vector<int>(9, 0));
	vs[s1][s2] = 1;
	while(!Q.empty()){
		C k = Q.front();
		Q.pop();
		if(k.h == f1 && k.c == f2){
			return k.cnt;
		}
		for(auto it : F){
			if(k.h + it.first >=0 && k.h + it.first <= 8 && k.c + it.second >= 0 && k.c + it.second <= 8){
				if(!vs[k.h + it.first][k.c + it.second]){
					vs[k.h + it.first][k.c + it.second] = 1;
					Q.push({k.h + it.first, k.c + it.second, k.cnt + 1});
				}
			}
		}
	}
}


int main() {
	//int test;
	//cin >> test;
	//while(test--){
		cin >> s1 >> s2 >> f1 >> f2;
		//vector<vector<int>> DP(9, vector<int>(9, 0));
		cout << BFS();
	//}
	return 0;
}
