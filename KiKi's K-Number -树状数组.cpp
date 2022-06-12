#include<iostream>
#include<cstdio>
#include<algorithm>	
#include<string>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 1e5 + 10;
int tree[maxn];
int n = maxn;
int lowbit(int x){
	return x & (-x);
}

void add(int loc,int val){
	for(int i = loc;i <= n;i += lowbit(i)){
		tree[i] += val;
	}
	/*
	while(i <= n){
		tree[i] += val;
		i += lowbit;
	}
	*/
}
int getsum(int loc){
	int ans = 0;
	for(int i = loc;i > 0;i-= lowbit(i)){
		ans += tree[i];
	}
	/*
	while(i > 0){
		ans += lowbit(i);
		i -= lowbit(i);
	}
	*/
	return ans;
}

int find(int a,int k){
	int cnt = getsum(a) + k;
	int l = a,r = n;
	while(l  <= r){	//l + 1 < r ��Ӧ l = mid ,r = mid ,return r ���� return l 
		int mid = (r - l) / 2 + l;//l <= r ��Ӧ l = mid + 1,r = mid - 1 ,return l ���� return r 
		if(getsum(mid) < cnt){	//l < r ��Ӧ  l = mid + 1,r = mid,return l ���� return r 
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return l;
}
int main(){
	int m = 0,e = 0,order = 0,a = 0,k = 0;
	while(scanf("%d",&m) != EOF && m){
		n = maxn;				//����� 
		memset(tree,0,sizeof(tree));
		for(int i = 0;i < m;++i){
			scanf("%d",&order);
			if(order == 0){
				scanf("%d",&e);
				add(e,1);
			}else if(order == 1){
				scanf("%d",&e);
				if(getsum(e) - getsum(e - 1) == 0){//����Ϊ0��ת���뻯�� 
					printf("No Elment!\n");
				}else{
					add(e,-1);
				}
			}else if(order == 2){
				scanf("%d %d",&a,&k);
				if(getsum(n) - getsum(a) < k){	//�Ⱥų����ٽ�������̽ 
					printf("Not Find!\n");
				}else{
					printf("%d\n",find(a,k));
				} 
			}
		}
	}
	
	return 0;
}
