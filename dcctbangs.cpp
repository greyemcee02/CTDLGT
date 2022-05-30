#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, sum;
vector<int> F;
bool ok = false;
int res = n;
void QL(int i, int cnt1, long long s){
	if(cnt1 > res || s > sum) return;
	if(i == F.size()){
		if(s == sum)
		res = min(cnt1, res);
		return;
	}
	QL(i + 1, cnt1 + 1, s+F[i]);
	QL(i + 1, cnt1, s);
}

int main() {
	cin >> n >> sum;
	int tmp, res = -1;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		if(tmp == sum) ok = true;
		else if(tmp < sum)
			F.push_back(tmp);
	}
	if(ok) cout << 1 << endl;
	else{
		sort(F.begin(), F.end(), greater<int>());
		QL(0, 0, 0);
		cout << res << endl;
	}
	return 0;
}
