#include<bits/stdc++.h>

using namespace std;

void out(int n) {
	vector<int> nums(n/2, 0);
	while(1) {
		if(n % 2 != 0) {
			for(int i = 0; i < n/2; i++)
				cout << nums[i] << " ";
			cout << 0 << " ";
			for(int i = n/2 - 1; i >= 0; i--)
				cout << nums[i] << " ";
			cout << endl;
			for(int i = 0; i < n/2; i++)
				cout << nums[i] << " ";
			cout << 1 << " ";
			for(int i = n/2 - 1; i >= 0; i--)
				cout << nums[i] << " ";
			cout << endl;
		}
		else{
			for(int i = 0; i < n/2; i++)
				cout << nums[i] << " ";
			for(int i = n/2 - 1; i >= 0; i--)
				cout << nums[i] << " ";
			cout << endl;
		}
		int i = n/2 - 1;
		while(i >= 0 && nums[i] ){
			nums[i] = 0;
			i--;
		}
		if(i == -1) break;
		else nums[i] = 1;
	}
}

int main() {
	int n;
	cin >> n;
	out(n);
	return 0;
}
