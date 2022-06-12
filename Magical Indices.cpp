#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
typedef long long LL;
const int maxn = 10000100;
struct Node{
	int num = -1;
	int loc = -1;
};
int ans = 0,n = 0;
Node data[maxn];
bool cmp(Node a,Node b){
	return a.num <= b.num;
}

int main(){
	int T = 0;
	scanf("%d",&T);
	getchar();
	while(T--){
		//getchar();
		scanf("%d",&n);
		getchar();
		ans = 0;
		//memset(data,-1,sizeof(data));
		for(int i = 1;i <= n;++i){
			data[i].num = -1;
			data[i].loc = -1;
		}
		for(int i = 1;i <= n ;++i){
			scanf("%d",&data[i].num);
		}
		for(int i = 2;i <= n - 1;++i){
			data[i].loc = i;
		}
		sort(data+1,data + n + 1,cmp);
		for(int i = 2;i <= n - 1;++i){
			if(data[i].loc == i){
				++ans;
			}
		}
		printf("%d\n",ans);
	}
	

	
	return 0;
} 
