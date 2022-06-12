#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define INF 100000 
using namespace std;
const int maxn = 20000;
int N = 0,M = 0,K = 0;

int A[maxn];

typedef struct cloth{
	int num;
	double val;
}Cloth;
Cloth shirt[maxn];
Cloth L[maxn/2],R[maxn/2];
bool compare(Cloth a,Cloth b){
	
	return a.val > b.val;
}
bool com(Cloth a,Cloth b){
	
	return a.num > b.num;
}
bool com1(int a,int b){
	
	return a > b;
}
void init(){
	for(int i = 0;i < M;++i){
		shirt[i].num = shirt[i].val = 0;
	}
}

void merge(int l,int mid,int r){
	int n1 = mid - l;
	int n2 = r - mid;
	for(int i = 0;i < n1;++i){
		L[i] = shirt[l + i];
	}
	for(int i = 0;i < n2;++i){
		R[i] = shirt[mid + i];
	}
	L[n1].val = R[n2].val = INF;
	int i = 0,j = 0;
	for(int k = l;k < r;++k){
		if(L[i].val >= R[j].val){
			shirt[k] = L[i++];
		}else{
			shirt[k] = R[j++];
		}
	}
	
}
void merge_sort(int l,int r){
	if(l + 1 < r){
		int mid = (r - l)/2 + l;
		merge_sort(l,mid);
		merge_sort(mid,r);
		merge(l,mid,r);
	}
}

int main(){
	while(cin >> N >> M >> K){
		init();
		double temp = 0;
		for(int i = 0;i < N;++i){
			for(int j = 0;j < M;++j){
				cin >> temp;
				shirt[j].val += temp;
				shirt[j].num = j + 1;
			}
		}
		
		sort(shirt,shirt + M,compare);
		//merge_sort(0,M);
		//int ans[maxn];
		//for(int i = 0;i < K;++i){
	//		ans[i] = shirt[i].num;
	//	}
		//sort(shirt + M - K - 1,shirt + M ,com);
		sort(shirt ,shirt + K,com);
		//sort(ans,ans + K,com1);
		for(int i = 0;i < K;++i){
			if(i){
				cout << " ";
			}
			//cout << ans[i] ;
			cout << shirt[i].num;
		}
		cout << endl;
	}
	
	
	return 0;
}
