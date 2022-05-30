#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> nums = {1, 2, 3, 4};
	nums.erase(nums.begin() + 1);
	for(auto it : nums)
		cout << it << " ";
		
	return 0;
}
