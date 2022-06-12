#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int maxn = 1e6 + 100;
set<int> st;
int ans[maxn];
int main(){
	int n = 0,m = 0;
	scanf("%d %d",&n,&m);
	int x = 0;
	for(int i = 0;i < n;++i){
		scanf("%d",&x);
		st.insert(x);
	}
	int num = 0;
	long long sum = 0;
	for(int i = 1;sum <= m;++i){
		if(st.find(i) == st.end()){
			if(sum + i > m){
				break;
			}
			ans[num++] = i;
			sum += i;
		}
	}
	printf("%d\n",num);
	for(int i = 0;i < num;++i){
		printf("%d ",ans[i]);
	}
	return 0;
}
