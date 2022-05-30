#include<bits/stdc++.h>

using namespace std;

int A[503][503], D[503][503];
int n, m;
vector<pair<int, int>> nxt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> A[i][j];
			D[i][j] = INT_MAX;
		}
	}
}

void Dijkstra(){
	D[1][1] = A[1][1];
	priority_queue<pair<int, pair<int, int>>,
					vector<pair<int, pair<int, int>>>,
					greater<pair<int, pair<int, int>>>> pq;
	pq.push({A[1][1], {1, 1}});
	while(!pq.empty()){
		int d = pq.top().first;
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		pq.pop();
		for(auto it : nxt){
			int ui = it.first, vi = it.second;
			if(u + ui >= 1 && u + ui <= n && v + vi >= 1 && v+ vi <= m){
				if(D[u + ui][v + vi] > d + A[u+ui][v+vi]){
					D[u + ui][v + vi] = d + A[u + ui][v + vi];
					pq.push({D[u+ui][v+vi], {u + ui, v+ vi}});
				}
			}
		}
	}
	cout << D[n][m] << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		input();
		Dijkstra();
	}
	return 0;
}
