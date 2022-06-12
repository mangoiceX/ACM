#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100;

int main(){
	int n = 0,key = 0;
	int data[maxn];	
	cin >> n ;
	for(int i = 0;i < n;i++){
		cin >> data[i];
	}
	sort(data,data + n);
	while(cin >> key){
		int num  = 0,l = 0,r = n - 1;
		
		while(l <= r){
			int temp = data[l] + data[r];
			if( temp > key){
				r--;	
			}else if(temp < key){
				l++;
			}else{
				cout << data[l] << " + " << data[r] << " = " << key << endl;
				l++;r--;
				num++;
			}
			
			
		}
		cout << "there are total " << num << " pairs of numbers with their sum being "
        	<< key << endl;
		
		
	}
	
	
	
	return 0;
} 
