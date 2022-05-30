#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
char x;
vector<int> nums(17);

void Try(string s, int c1, int c2, int a, int b){
	if(s.length() == n){
		if(x == 'O' && a > b && a>= 5) cout << s << endl;
		else if(x == 'X' && b > a && b>= 5) cout << s << endl; 
		return;
	}
	if(s.length() == 0){
		Try(s +'O', c1+1, c2, a + 1, b);
		Try(s +'X', c1, c2 + 1, a, b + 1);
	}
	else if(s[s.length() - 1] == 'O'){
		Try(s +'O', c1+1, 0, max(a, c1 + 1), b);
		Try(s +'X', 0, 1, a, max(b, 1));
	}
	else{
		Try(s +'O', 1, 0, max(a, 1), b);
		Try(s +'X', 0, c2 + 1, a, max(c2 + 1,b));	
	}
}


int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> x;
		Try("", 0, 0, 0, 0);
	}
	return 0;
}
