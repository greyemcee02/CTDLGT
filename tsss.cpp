#include<bits/stdc++.h>
using namespace std;
int a[20], n;
bool check[20];
void in(){
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << endl;
}
bool kt(){
	for(int i = 1; i <= n; i++)
		if(abs(a[i] - a[i-1]) == 1) return false;
	return true;
}
void ql(int i){
	for(int j = 1; j <= n; j++){
		if(check[j]){
			check[j] = false;
			a[i] = j;
			if(i == n){
				if(kt()) in();
			}
			else ql(i+1);
			check[j] = true;
		}
	}
}
main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		memset(check, true, sizeof(check));
		ql(1);
		cout << endl;
	}
}
