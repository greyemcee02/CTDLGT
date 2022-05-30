#include<bits/stdc++.h>

using namespace std;


int main() {
	string str;
	vector<int> stk;
	while((cin >> str)){
		if(str == "push"){
			int n;
			cin >> n;
			stk.push_back(n);
		}
		else if(str == "show"){
			if(stk.size() == 0) cout << "empty" << endl;
			else{
				for(auto it : stk)
					cout << it << " ";
				cout << endl;
			}
		}
		else stk.pop_back();
	}
	return 0;
}
