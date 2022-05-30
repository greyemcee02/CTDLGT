#include<bits/stdc++.h>

using namespace std;
int n;
struct Job{
	int jobld, Deadline, profit;
};

bool cmp(Job j1, Job j2){
	if(j1.Deadline < j2.Deadline) return true;
	else if(j1.Deadline == j2.Deadline){
		if(j1.profit < j2.profit) return true;
	}
	return false;
}

void solve(vector<Job> CV){
	int sz = CV[n-1].Deadline;
	int res = 0, s = 0;
	for(int i = sz; i >= 1; i--){
		int k = -1;
		int x = -1;
		for(int j = CV.size() - 1; j >= 0; j--){
			if(CV[j].Deadline < i) break;
			if(k < CV[j].profit){
				k = CV[j].profit;
				x = j;
			}
		}
		if(x != -1){
			res += k;
			CV[x].profit = -1;
			s++;
		}
		
	}
	cout << s << " "<< res << endl;
}

int main() {
	int test;
	cin >> test;
	while(test--){
	
		cin >> n;
		vector<Job> CV(n);
		for(int i = 0; i < n; i++){
			cin >> CV[i].jobld >> CV[i].Deadline >> CV[i].profit;
		}
		sort(CV.begin(), CV.end(), cmp);
		solve(CV);
//		for(int i = 0; i < n; i++){
//			cout << CV[i].jobld << " " <<  CV[i].Deadline << " " << CV[i].profit << endl;
//		}
	}
	return 0;
}
