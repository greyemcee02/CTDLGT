#include<iostream>
#include<vector>
#include<list>
#include<sstream>
using namespace std;

void solve(list<pair<int, int>> dt1, list<pair<int, int>> dt2){
	list<pair<int, int>> res;
	auto h1 = dt1.begin(), h2 = dt2.begin();
	while(h1 != dt1.end() && h2 != dt2.end()){
		if(h1->second  == h2->second){
			res.push_back({h1->first + h2->first, h1->second});
			h1++;
			h2++;
		}
		else if(h1->second > h2->second){
			res.push_back({h1->first, h1->second});
			h1++;
		}
		else{
			res.push_back({h2->first, h2->second});
			h2++;
		}
	}
	while(h1 != dt1.end()){
		res.push_back({h1->first, h1->second});
		h1++;
	}
	while(h2 != dt2.end()){
		res.push_back({h2->first, h2->second});
		h2++;
	}
	int cnt = res.size();
	for(auto it : res){
		cout << it.first << "*x^" << it.second;
		if(cnt > 1)
			cout << " + ";
		cnt--; 
	}
	cout << endl;
}

int main() {
	int test;
	cin >> test;
	cin.ignore();
	while(test--){
		list<pair<int, int>> dt1, dt2;
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		for(int i = 0; i < s1.length(); i++){
			if(!isdigit(s1[i]))
				s1[i] = ' ';
		}
		for(int i = 0; i < s2.length(); i++){
			if(!isdigit(s2[i]))
				s2[i] = ' ';
		}
		int t1, t2;
		istringstream is(s1);
		while(is >> t1){
			is >> t2;
			dt1.push_back({t1, t2});
		}
		istringstream is1(s2);
		while(is1 >> t1){
			is1 >> t2;
			dt2.push_back({t1, t2});
		}
		solve(dt1, dt2);
		
	}
	return 0;
}
//1
//3*x^8 + 7*x^2 + 4*x^0
//11*x^6 + 9*x^2 + 2*x^1 + 3*x^0
