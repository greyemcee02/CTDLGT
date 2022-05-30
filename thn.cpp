#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, k;
vector<int> nums(20, 0);
void Try(int i ){
	for(int j = n - k + i; j >= nums[i-1]+1;j--){
		nums[i] = j;
		if(i == k) {
			for(int i = 1; i <= k; i++)
				cout << nums[i] << " ";
			cout << endl;
		}
		else Try(i + 1);
			
	}
}

int main() {
	int test;
	cin >> test;
	while(test--){
		cin >> n >> k;
		nums[0] = 0;
		Try(1);	
	}
	return 0;
}
