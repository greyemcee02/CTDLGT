#include<bits/stdc++.h>

using namespace std;
int n, m;


int solve(vector<int> nums){
	vector<int> left(m), right(m);
	stack<int> stk1;
	left[0] = -1;
	stk1.push(0);
	for(int i = 1; i < m; i++){
		if(stk1.empty()){
			left[i] = -1;
		}
		else{
			while(!stk1.empty() && nums[i] <= nums[stk1.top()])
				stk1.pop();
			if(stk1.empty()){
				left[i] = -1;
			}
			else left[i] = stk1.top();
		}
		stk1.push(i);
	}
	
	stack<int> stk2;
	right[m-1] = m;
	stk2.push(m);
	for(int i = m-2; i >= 0; i--){
		if(stk2.empty()){
			right[i] = m;
		}
		else{
			while(!stk2.empty() && nums[i] <= nums[stk2.top()])
				stk2.pop();
			if(stk2.empty()){
				right[i] = m;
			}
			else right[i] = stk2.top();
		}
		stk2.push(i);
	}
	int s = 0;
	for(int i = 0; i < m; i++){
		s = max(s, (right[i]-left[i]-1)*nums[i]); 
	}
	return s;
}

void result(vector<vector<int>> &Grid){
	int res = 0;
	for(int i = 0; i < n; i++){
		res = max(res, solve(Grid[i]));
	}
	cout << res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> m;
		vector<vector<int>> Grid(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> Grid[i][j];
		}
		for(int i = 1; i < n; i++){
			for(int j = 0; j < m; j++)
				if(Grid[i][j])
					Grid[i][j] += Grid[i-1][j];
		}
		result(Grid);
	}
	return 0;
}
