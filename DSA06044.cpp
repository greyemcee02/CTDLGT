#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	vector<int> num1, num2;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(i%2 == 0) num1.push_back(tmp);
		else num2.push_back(tmp);
	}
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end(), greater<int>());
	int p1 = 0, p2 = 0;
	while(p1 < num1.size() || p2 < num2.size()){
		if(p1 < num1.size()){
			cout << num1[p1++] << " ";
		}
		if(p2 < num2.size()){
			cout << num2[p2++] << " ";
		}
	}
	return 0;
}
