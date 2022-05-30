#include<bits/stdc++.h>

using namespace std;
vector<string> DP(101);

string operator *(string &a, string &b){
	while(a.length() < b.length())
		a = "0" + a;
	while(b.length() < a.length())
		b = "0" + b;
	vector<int> nums(a.length() + b.length() + 1, 0);
	for(int i = a.length() - 1; i >= 0; i--){
		for(int j = b.length() - 1; j >= 0; j--){
			nums[i+j+2] += (a[i] - '0') * (b[j] - '0');
		}
	}
	int i = 0;
	for(int i = nums.size() - 1; i >= 1; i--){
		nums[i-1]+= nums[i]/10;
		nums[i] = nums[i]%10;
	}	
	bool ok = false;
	string res;
	for(int i = 0; i < nums.size(); i++){
		if(nums[i] == 0 && !ok);
		else{
			ok = true;
			res.push_back((nums[i] +'0'));
		}
	}
	return res;
}

string sum(string &a, string &b){
	int nho = 0;
	string res;
	int i = a.length() - 1, j = b.length() - 1;;
	while(i >=0 && j >= 0){
		int t = (a[i] - '0') + (b[j] - '0') + nho;
		res = (char)(t%10 + '0') + res;
		nho = t/10;
		i--;
		j--;
	}
	while(i >= 0){
		int t = (a[i] -'0') + nho;
		res = (char)(t%10 + '0') + res;
		nho = t/10;
	}
	while(j >= 0){
		int t = (b[j] -'0') + nho;
		res = (char)(t%10 + '0') + res;
		nho = t/10;
	}
	if(nho > 0){
		res = (char)(nho + '0') + res;
	}
	return res;
}

void solve(){
	DP[0] = "1";
	DP[1] = "1";
	for(int i = 2; i <= 100; i++){
		string s;
		for(int j = 0; j <= (i-1)/2; j++){
			string k = DP[j]*DP[i-1-j];
			s = sum(s, k);
		}
		cout << s << endl;
	}
}

int main() {
	solve();
	//for(int i = 0; i <= 100; i++)
	//	cout << DP[i] << endl;
	//for(int i = 0; i <= 100; i++)
	//	cout << DP[i] << endl;
	//int test;
	//cin >> test;
	//while(test--){
		
	//}
	
	return 0;
}
