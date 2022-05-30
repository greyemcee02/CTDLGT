#include<bits/stdc++.h>

using namespace std;
char C;
vector<int> check(8, 0);

bool  kt(string str){
	int a = str.length();
	if(a<3) return false;
	if(str[a-1] != 'A' && str[a-1] != 'E'){
		if(str[a - 2] == 'A' || str[a-2] == 'E'){
			if(str[a-3] != 'A' && str[a-3] != 'E') return true;
		}
	}
	return false;
}

void Try(int i, string str){
	for(int j = 0; j <= C - 'A'; j++){
		if(!check[j]){
			check[j] = 1;
			str.push_back((char)('A' + j));
			if(i == C - 'A' || kt(str)){
				if(kt(str));
				else if(i == C - 'A'){
					cout << str << endl;
				}
			}
			else Try(i + 1, str);
			check[j] = 0;
			str.pop_back();
		}
	}
}

int main() {
	cin >> C;
	for(int i = C - 'A' + 1; i <= 7; i++)
		check[i] = 1;
	string str;
	Try(0, str);
	return 0;
}

