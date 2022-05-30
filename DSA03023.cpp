#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string str;
	cin >> str;
	int X = 0, T = 0, D = 0;
	for(auto it : str){
		if(it == 'X') X++;
		else if(it == 'T') T++;
		else D++; 
	}
	int res = 0;
	
	cout << res << endl;
	return 0;
}
