#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 100;
typedef  long long LL; 
LL data[maxn];
LL tree[maxn];
int n = 0,k = 0;
struct Node{
	LL sum = 0;
};

Node node[maxn];



int lowbit(int x){
	return x & (-x);
}

void update(int loc,int val){
	while(loc <= n){
		tree[loc] += val;
		loc += lowbit(loc);
	}
}

int getsum(int loc){
	int sum = 0;
	while(loc > 0){
		sum += tree[loc];
		loc -= lowbit(loc);
	}
	return sum;
}

int main(){
	
	cin >> n >> k;
	memset(tree,0,sizeof(tree));
	for(int i = 1;i <= n;++i ){
		cin >> data[i];
		update(i,data[i]);
	}

	for(int i = k;i <= n;++i){
		node[i-k+1].sum = getsum(i) - getsum(i-k);
	}
	
	int left[maxn],maxl = 1;
	left[1] = 1;
	for(int i = 2;i <= n-k+1;++i){
		if(node[i].sum > node[maxl].sum){
			left[i] = i;
			maxl = i;
		}else{
			left[i] = maxl;
		}
	}
	
	int right[maxn],maxr = n-k+1;
	right[n-k+1] = n-k+1;
	for(int i = n-k;i >= 1;--i){
		if(node[i].sum >= node[maxl].sum){
			right[i] = i;
			maxr = i;
		}else{
			right[i] = maxr;
		}
	}
	
	LL maxv= 0 ;
	int l = 0,r = 0;
	for(int i = 1;i <= n-k+1-k;++i){
		int j = i + k;
		if(node[left[i]].sum + node[right[j]].sum > maxv){
			maxv = node[left[i]].sum + node[right[j]].sum;
			l = left[i],r = right[j];
		}
	}
	cout << l << " " << r << endl;
	return 0;
}
