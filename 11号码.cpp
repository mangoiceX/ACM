#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(){
	string ans;
	int N = 0;
	
	
	
	cin >> N;
	while(N--){
		cin >> ans;
		cout << "6";
		for(int i = 6;i < 11;i++){
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
