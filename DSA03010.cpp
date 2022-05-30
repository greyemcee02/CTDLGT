#include<iostream>
#include<queue>

using namespace std;


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n;
		long long res = 0, tmp;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<int>> Q;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			Q.push(tmp);
		}
		while(Q.size() > 1){
			long long a = Q.top();
			Q.pop();
			long long b = Q.top();
			Q.pop();
			res += a + b;
			Q.push(a + b); 
		}
		cout << res << endl;
	}
	return 0;
}
