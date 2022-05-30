#include<bits/stdc++.h>

using namespace std;

queue<int> Q;

void solve(string str){
	int k;
	if(str == "PUSH") k = 1;
	else if(str == "PRINTFRONT") k = 2;
	else k = 3;
	switch(k){
		case 1:
			int num;
			cin >> num;
			Q.push(num);
			break;
		case 2:
			if(Q.empty()) cout << "NONE" << endl;
			else cout << Q.front() << endl;
			break;
		case 3:
			if(!Q.empty())
				Q.pop();
			break;
	}
}


int main(){
	int n;
	cin >> n;
	string str;
	for(int i = 0; i < n; i++){
		cin >> str;
		solve(str);
	}	
	return 0;
}
