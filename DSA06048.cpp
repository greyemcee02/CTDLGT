#include<bits/stdc++.h>

using namespace std;



int main() {
	int test;
	cin >> test;
	while(test--) {
		int size;
		cin >> size;
		long long mn;
		int res = 0;
		cin >> mn;
		for(int i = 1; i < size; i++){
			long long tmp;
			cin >> tmp;
			if(tmp < mn){
				mn = tmp;
				res = i;
			} 
		} 
		cout << res << endl;
	}
	return 0;
}

