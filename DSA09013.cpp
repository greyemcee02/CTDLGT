#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int V, E;

void DFS(vector<vector<int>> DSK, vector<int> &vs, int a, int b, int u){
    stack<int> stk;
    stk.push(u);
    vs[u] = 1;
    while(!stk.empty()){
        int v = stk.top();
        stk.pop();
        for(auto it : DSK[v]){
            if((v==a && it == b) || (v == b && it == a)) continue;
            else{
                if(vs[it] == 0){
                    stk.push(v);
                    stk.push(it);
                    vs[it] = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    int test;
    cin >> test;
    while(test--){
        cin >> V >> E;
        vector<pair<int, int>> DSC; 
        vector<vector<int>> DSK(V + 1);
        int u, v;
        for(int i = 0; i < E; i++){
            cin >> u >> v;
            DSC.push_back({u, v});
            DSK[u].push_back(v);
            DSK[v].push_back(u);
        }
        vector<pair<int, int>> res;
        for(int i = 0; i < E; i++){
            vector<int> vs(V + 1, 0);
            int lt = 0;
            for(int j = 1; j <= V; j++){
                if(vs[j] == 0){
                    DFS(DSK, vs, DSC[i].first, DSC[i].second, j);
                    lt++;
                }
            }
            if(lt > 1){
                res.push_back(DSC[i]);
            }
        }
        for(auto it : res)
            cout << it.first << " " << it.second << " ";
        cout << endl;
    }
    return 0;
}