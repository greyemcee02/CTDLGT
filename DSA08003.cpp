#include<bits/stdc++.h>

using namespace std;

deque<int> DQ;

int CD(string str){
	if(str == "PUSHFRONT") return 1;
	if(str == "PRINTFRONT") return 2;
	if(str == "POPFRONT") return 3;
	if(str == "PUSHBACK") return 4;
	if(str == "PRINTBACK") return 5;
	return 6;
}

void solve(string str){
	switch(CD(str)){
		case 1:
			int x;
			cin >> x;
			DQ.push_front(x);
			break;
		case 2:
			if(DQ.empty()) cout << "NONE" << endl;
			else cout << DQ.front() << endl;
			break;
		case 3:
			if(!DQ.empty())
				DQ.pop_front();
			break;
		case 4:
			int x1;
			cin >> x1;
			DQ.push_back(x1);
			break;
		case 5:
			if(DQ.empty()) cout << "NONE" << endl;
			else cout << DQ.back() << endl;
			break;
		case 6:
			if(!DQ.empty())
				DQ.pop_back();
			break;
	}
}

int main() {
	int n;
	cin >> n;
	string tv;
	for(int i = 0; i < n; i++){
		cin >> tv;
		solve(tv);
	}
	return 0;
}
