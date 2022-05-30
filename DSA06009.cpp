#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> count, int num) {
	int res = 0;
	for(int i = 0; i <= num/2; i++){
		res += count[i]*count[num - i];
	}
	if(num % 2 == 0)
		res += -count[num/2]*count[num/2] + count[num/2] * (count[num/2] - 1)/2;
	return res;
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		int size, num, tmp;
		cin >> size >> num; 
		vector<int> count(1001, 0);
		for(int i = 0; i < size; i++){
			cin >> tmp;
			count[tmp]++;
		}
		cout << solve(count, num) << endl;
	}	
	return 0;
}

