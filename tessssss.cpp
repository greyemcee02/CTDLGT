#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    double t1 = (double)a.first/a.second;
    double t2 = (double)a.first/a.second;
    return (t1 > t2);
}

vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    vector<pair<int>> num(aliceArrows.size());
    for(int i = 0; i < aliceArrows.size(); i++){
        num.push_back({i, aliceArrows[i] + 1});
    }
    //sort(num.begin(), num.end(), cmp);
    for(auto it : num)
        cout << it.first << " " << it.second << endl;
    
    return {};
}   

int main() {

    return 0;
}
