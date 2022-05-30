#include<bits/stdc++.h>

using namespace std;

int main() {
	double x;
	cin >> x;
	while(x != 0){
		x*= 2;
		if(x >= 1){
			cout << 1;
			x-=1;
		}
		else cout << 0;
	}
	return 0;
}
