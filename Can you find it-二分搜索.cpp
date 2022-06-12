
//Can you find it? £¨¶þ·Ö£©
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 505;

int A[maxn],B[maxn],C[maxn];
int AB[500* 500 + 1];
bool binary(int key1,int k){
	
	int l = 0,r = k - 1;
	while(l <= r){
		int mid = (r - l)/2 + l;
		if(AB[mid] == key1){
			return true;
		}else if(AB[mid] < key1){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return false;
	
	/*
	if(key1 == AB[lower_bound(AB,AB+k,key1)-AB])
        return true;
    else
        return false;
        */
}
bool solve(int L,int N,int M,int key,int k){
	
	
	for(int i = 0;i < M;i++){
		if(binary(key - C[i],k)){
			return true;
		}
	}
	
	return false;	
}

int main(){
	int zu = 0;
	int L = 0,N = 0,M = 0,S = 0,key = 0;
	while(scanf("%d %d %d",&L,&N,&M) != EOF){
		++zu;
		//getchar();
		for(int i = 0;i < L;++i){
			scanf("%d",&A[i]);
		}
		for(int i = 0;i < N;++i){
			scanf("%d",&B[i]);
		}
		for(int i = 0;i < M;++i){
			scanf("%d",&C[i]);
		}
		
	//	sort(A,A + L);
	//	sort(B,B + N);
		sort(C,C + M);
		int k = 0;
		for(int i = 0;i < L;++i){
			for(int j = 0;j < N;++j){
				AB[k++] = A[i] + B[j];
			}
		}
		
	sort(AB,AB + k);
		
		scanf("%d",&S);
		printf("Case %d:\n",zu);
		while(S--){
			scanf("%d",&key);
			if(solve(L,N,M,key,k)){
				printf("YES\n");
			}else{
				printf("NO\n");
			} 
		}
	}
	
	
	
	return 0;
}
