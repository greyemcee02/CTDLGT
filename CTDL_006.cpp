#include<iostream>
#include<list>
using namespace std;

int main() {
	int n, tmp;
	cin >> n;
	list<int> ls;
	for(int i = 0; i < n; i++){
		bool ok = true;
		cin >> tmp;
		for(auto it : ls)
			if(it == tmp) ok = false; 
		if(ok) ls.push_back(tmp);
	}
	for(auto it : ls)
		cout << it << " ";
	return 0;
}
