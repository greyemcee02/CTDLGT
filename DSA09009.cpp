#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int V, E;
vector<vector<int>> DSK(10001);
void BFS(vector<int> &vs, int u){
    queue<int> Q;
    Q.push(u);
    vs[u] = 1;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(auto it : DSK[v]){
            if(!vs[it]){
                Q.push(it);
                vs[it] = 1;
            }
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> V >> E;
        int u, v;
        for(int i = 0; i <= V; i++)
            DSK[i].clear();
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            DSK[u].push_back(v);
            DSK[v].push_back(u);
        }
        int lt = 0;
        vector<int> vs(V + 1, 0);
        for(int i = 1; i <= V; i++){
            if(!vs[i]){
                BFS(vs, i);
                lt++;
            }
        }
        cout << lt << endl;
    }
    return 0;
}