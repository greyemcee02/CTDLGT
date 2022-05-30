#include<bits/stdc++.h>

using namespace std;
int sum;

bool Try(map<int, int> &count, map<int, int> :: iterator it, int cnt, int k, int s) {
	if(cnt == k) return true;
	for(map<int, int> :: iterator i = it; i!= count.end(); i++){
		if((*i).second){
			s += (*i).first;
			(*i).second--;
			if(s == sum && (Try(count, count.begin(), cnt + 1, k, 0))) return true;
			else if(s < sum){
				if(Try(count, i, cnt, k, s))
					return true;
			}
			s -= (*i).first;
			(*i).second++;
		}
	
	}	
	return false;
	
}


bool solve(int k, int n, map<int, int> &count){
	if(k == 1) return true;
	if(k > n) return false;
	if(sum % k != 0) return false;
	sum/=k;
	//map<int, int> :: iterator i = count.begin();
	return Try(count, count.begin(), 0, k, 0);
}


int main() {
	int test;
	cin >> test;
	while(test--) {
		int n, k;
		cin >> n >> k;
		map<int, int> count;
		int tmp;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> tmp;
			sum += tmp;
			count[tmp]++;
		}
		if(solve(k, n, count)) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
