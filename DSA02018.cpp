#include<bits/stdc++.h>

using namespace std;
int nums[5];
bool ok;
int cnt = 0;
void Try(int i, int s, int vec[]){
	for(int j = 1; j <= 3 && !ok; j++){
		if(j == 1) s += vec[i];
		else if(j == 2) s -= vec[i];
		else s *= vec[i];
		if(i == 4 ){
			if(s == 23){
				ok = true;
			}
		}	
		else 
			Try(i + 1, s, vec);
		if(j == 1) s -= vec[i];
		else if(j == 2) s += vec[i];
		else s /= vec[i];
	}
}

void Try1(int i, int vec[], int check[]){
	for(int j = 0; j < 5 && !ok; j++){
		if(!check[j]){
			check[j] = 1;
			vec[i] = nums[j];
			if(i == 4){
				Try(1, vec[0], vec);
			}
			else Try1(i + 1, vec, check);
			check[j] = 0;
		}
	}
}
int main() {
	int test;
	cin >> test;
	while(test--){
		ok = false;
		cnt = 0;
		int vec[5] = {0}, check[5] = {0};
		for(int i = 0; i < 5; i++)
			cin >> nums[i];
		Try1(0, vec, check);
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
