#include<bits/stdc++.h>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vector<long long> nums1(n1), nums2(n2), nums3(n3);
		for(int i = 0; i < n1; i++) cin >> nums1[i];
		for(int i = 0; i < n2; i++) cin >> nums2[i];
		for(int i = 0; i < n3; i++) cin >> nums3[i];
		int p1 = 0, p2 = 0, p3 = 0;
		bool ok = false;
		while( p1 < n1 && p2 < n2 && p3 < n3){
			if(nums1[p1] < nums2[p2]) p1++;
			else if(nums1[p1] > nums2[p2]) p2++;
			else{
				if(nums2[p2] == nums3[p3]){
					cout << nums1[p1] << " ";
					p1++;
					p2++;
					p3++;
					ok = true;
				}	
				else if(nums2[p2] > nums3[p3]) p3++;
				else{
					p1++;
					p2++;
				}
			}
		}
		if(ok == false) cout << -1 ;
		cout << endl;
	} 
	return 0;
}
