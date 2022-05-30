#include<bits/stdc++.h>

using namespace std;


void bubleSort(vector<int> &nums){
	int cnt = 1; 
	for(int i = nums.size() - 1; i > 0 ; i--){
		cout << "Buoc " << cnt++ << ": ";
		bool check = true;// kiem tra xem da sap xep xong chua
		for(int j = 0; j < i; j++){
			if(nums[j] > nums[j + 1])
				swap(nums[j], nums[j+1]);
		}
		for(int i = 0; i < nums.size(); i++){// in ra vector
			cout << nums[i] << " ";
			if(i < nums.size() - 1){
				if(nums[i] > nums[i + 1]) check = false; // neu mang chua sap xep gan check = false
			}
		}	
		cout << endl;
		if(check) break;// neu check = true -> mang da sap xep -> out
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	bubleSort(nums);
	return 0;
}
