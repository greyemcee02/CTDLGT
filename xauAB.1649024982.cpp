#include<iostream>
#include<string>

using namespace std;
int n;
char F[20];

void in(){
	bool ok = false;
	for(int j = 0; j < n; j++){
		cout << (char)(F[j] + 'A');
		if(F[j] == 0) ok = true;
	}
	if(ok) cout << ',';
	else
	cout << endl;
}

void NP(int i){
	for(int j = 0; j <= 1; j++){
		F[i] = j;
		if(i == n - 1) in();
		else NP(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		NP(0);	
	}
	return 0;
}
