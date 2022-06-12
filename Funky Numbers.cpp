#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n = 0;
int data[10000000];

bool solve(){	
	int l = 0,r = n;
	while(l < r){
		if(data[l] + data[r] < n){
			l++;
		}else if(data[l] + data[r] > n){
			r--;
		}else{
			return true;
		}
	}
	return false;	
}
int main(){
	
	while(scanf("%d",&n)!= EOF){
		for(int i = 1;i <= n;i++){
			data[i] = i*(i+1)/2;
		}
		if(solve()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
		
	}
	
	
	return 0;
}
