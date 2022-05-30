#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> save(11);

void in(int a) {
	cout << "(";
	for(int i = 1; i < a; i++) {
		cout << save[i] << " ";
	}
	cout << save[a] << ")" << " ";
}

void Try(int i, int s, int sum) {
	for(int j = s; j >= 1; j--) {
		if(sum + j <= n) {
			sum += j;
			save[i] = j;
			if(sum == n) in(i);
			else Try(i + 1, save[i], sum);
			sum -= j;
		}
	}
}

int main() {
	int test;
	cin >> test;
	while(test--) {
		cin >> n;
		Try(1, n, 0);
		cout << endl;
	}
	return 0;
}


