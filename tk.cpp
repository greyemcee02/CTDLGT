#include<iostream>
#include<sstream>
using namespace std;



int main() {
	int stack[1000];
	int sz = -1;
	string str;
	while((cin >> str)){
		if(str == "PUSH"){
			int k;
			cin >> k;
			sz++;
			stack[sz] = k;
		}
		else if(str == "POP"){
			if(sz > -1){
				sz--;
			}
		}
		else{
			cout << stack[sz] << endl;
		}
		
	}
	return 0;
}
