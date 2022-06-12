#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;

int data[maxn];

int main(){
	int t;
 	cin >> t;
	for(int i = 0;i < t;++i){
		cin >> data[i];
	}
	
	sort(data,data+t);
	
	for(int i = 1;i < t;++i){
		if(data[i] == data[i-1]){
			for(int j = i;j < t - 1;++j){
				data[j] = data[j+1];	
			}
			--i;
			--t;
		}
	}
	
	cout << t << endl;
	for(int i = 0;i < t;++i){
		cout << data[i] << " ";
	}
	cout << endl;
	
	return 0;
}
