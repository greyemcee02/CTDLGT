#include<bits/stdc++.h>


using namespace std;

string res;
int check;
bool solve(string str){
	int a = (str[0] - '0') * 10 + (str[1] - '0');
	int b = (str[5] - '0') * 10 + (str[6] - '0');
	int kq = (str[10] - '0') * 10 + (str[11] - '0');
	char pt = str[3];
	if(a < 10 || b < 10 || kq < 10) return false;
	if(pt == '+'){
		if(a + b == kq) return true;
	}
	if(pt == '-'){
		if(a - b == kq) return true;
	}
	if(pt == '*'){
		if(a * b == kq) return true;
	}
	if(pt == '/'){
		if(b != 0 && a%b==0){
			if(a / b == kq) return true;
		}
	}
	return false;
}

void Try(int i, string str) {
	if(check) return;
	if(i == 3){
		if(str[i] == '?'){
			str[i] = '*';
			Try(i + 1, str);
			str[i] = '+';
			Try(i + 1, str);
			str[i] = '-';
			Try(i + 1, str);
			str[i] = '/';
			Try(i + 1, str);
			str[i] = '?';
		}
		else Try(i + 1, str);
	}
	else{
		if(i == 12){
			if(solve(str)){
				res = str;
				check = true;
			}
		} 
		else if(str[i] == '?'){
			for(int j = 0; j <= 9; j++){
				str[i] = (char)('0' + j);
				Try(i+1, str);
				str[i] = '?';
			}
		}
		else Try(i + 1, str);
	}
	
}

int main() {
	int test;
	cin >> test;
	cin.ignore();
	while(test--) {
		string str;
		getline(cin, str);
		check = false;
		res =  "WRONG PROBLEM!";
		Try(0, str);
		cout << res << endl;
	}
 //	cout << (int)('+') << " " << (int)('-') << " " << (int)('*') << " " << (int)('/');
	return 0;
}
