#include<bits/stdc++.h>

using namespace std;

int main() {
	for(int x = 0; x < 100; x++){
		unsigned long long k = pow(3, x);
		for(int y = 0; y < x; y++ ){
			unsigned long long z = pow(2, y);
			if(y + (k - z) < x) cout << x << " " << y << endl;
		}
	}
	return 0;
}
