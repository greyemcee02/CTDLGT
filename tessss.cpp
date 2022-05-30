#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n = 12;
	int i = 1;
	while(i < 21a){
		i++;
		n *= 12;
		n = n % (1000000007);
	}
	cout << n << endl;
	
	return 0;
}
