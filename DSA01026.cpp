#include<bits/stdc++.h>

using namespace std;
int n;

void Try(int i, string str){
	if(i > 3 && str[i - 1] == '6' && str[i-2] == '6' && str[i-3] == '6'){
		str[i] = '8';
		if(i == n - 2){
			if(str[i-1]!='6' || str[i-2]!= '6' || str[i] != '6')
				cout << str << endl;
		} 
		else Try(i + 1, str);
	}
	else{
		str[i] = '6';
		if(i == n - 2) {
			if(str[i-1]!='6' || str[i-2]!= '6'||str[i]!='6')
				cout << str << endl;
		}
		else Try(i + 1, str);
		if(str[i-1] == '6'){
			str[i] = '8';
			if(i == n - 2){
				if(str[i-1]!='6' || str[i-2]!= '6'||str[i]!='6')
					cout << str << endl;
			}
				
			else Try(i + 1, str);
		}
	}
}

int main() {
	cin >> n;
	string str(n,'6');
	str[0] = '8';
	str[1] = '6';
	str[n - 1] = '6';
	Try(2, str);
	return 0;
}

