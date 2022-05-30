#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int V, E;
vector<vector<int>> DSK(10001);
void DFS(vector<int> &vs, int u){
    stack<int> stk;
    stk.push(u);
    vs[u] = 1;
    while(!stk.empty()){
        int v = stk.top();
        stk.pop();
        for(auto it : DSK[v]){
            if(!vs[it]){
                stk.push(v);
                stk.push(it);
                vs[it] = 1;
                break;
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
                DFS(vs, i);
                lt++;
            }
        }
        cout << lt << endl;
    }
    return 0;
}