#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num[200005];

bool test(int *num,int n){
	
	for(int i = 0;i < n - 1;i++){
		
		if(num[2*i] < num[2*i+2] && num[2*i] < num[2*i+3] &&
		num[2*i + 1] < num[2*i+2] && num[2*i + 1] < num[2*i+3]){
			return false;
		}
			
	}
	return true;
}
int main(){
	int N = 0;
	int cnt = 0;
	cin >> N;
	int n = N;
	while(N--){
		cin >> num[cnt] >> num[cnt+1];
		cnt += 2;
	}
	
	if(test(num,n)){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	
	
	return 0;
}

