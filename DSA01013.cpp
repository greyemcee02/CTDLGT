#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
	int test;
	cin >> test;
	while(test--){
		vector<string> gray;
		vector<string> binary;
		string str;
		cin >> str;
		gray.push_back("0");
		gray.push_back("1");
		binary.push_back("0");
		binary.push_back("1");
		for(int i = 0; i < str.length() - 1; i++) {
			vector<string> tmp1;
			vector<string> tmp2;
			for(int j = 0; j < gray.size(); j++){
				tmp1.push_back("0" + gray[j]);
				tmp2.push_back("0" + binary[j]);
			}
			for(int j = gray.size() - 1; j >= 0; j--){
				tmp1.push_back("1" + gray[j]);
				tmp2.push_back("1" + binary[gray.size() - 1 - j]);
			}
			gray = tmp1;
			binary = tmp2;
		}
		for(int i = 0; i < gray.size(); i++) {
			if(gray[i] == str){
				cout << binary[i] << endl;
				break;
			}
		}
	}
	return 0;
}
