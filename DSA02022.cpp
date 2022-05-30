#include<bits/stdc++.h>

using namespace std;
int n, mn = INT_MAX;
int C[20][20];
int kq = INT_MAX;
int check[20] = {0}, save[20];

void Try(int i, int s){
	for(int j = 2; j <= n; j++){
		if(!check[j]) {
			save[i] = j;
			check[j] = 1;
			s += C[save[i - 1]][j];
			if(i == n){
				kq = min(kq, s + C[j][1]);
			}
			else if(s + mn*(n - i + 1) < kq)
				Try(i + 1, s);
			s-= C[save[i-1]][j];
			check[j] = 0;
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++){
			cin >> C[i][j];
			if(C[i][j] != 0)
				mn = min(mn, C[i][j]);
		}
	save[1] = 1;
	Try(2, 0);
	cout << kq << endl;
	return 0;
}


