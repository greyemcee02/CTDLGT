#include<bits/stdc++.h>

using namespace std;

bool ktnt(int num){
	if(num == 2) return true;
	if(num < 2 || num % 2 == 0) return false;
	for(int i = 3; i <= sqrt(num); i+=2) {
		if(num % i == 0) return false;
	}
	return true;
}

void solve(int num, int &num1, int &num2){
	for(int i = 2; i <= num/2; i++){
		if(ktnt(i) && ktnt(num - i)){
			num1 = i;
			num2 = num - i;
			break;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		cin >> n;
		int num1 = -1, num2 = -1;
		solve(n, num1, num2);
		if(num1 == -1) cout << num1 << endl;
		else cout << num1 << " " << num2 << endl;
	}
	return 0;
}
