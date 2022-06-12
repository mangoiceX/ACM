#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)

using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
int a[maxn],b[maxn];
int n = 0;
void solve(){
	stack<int> st0,st1;
	st0.push(a[1]); st1.push(b[1]);
	int ans = n;
	per(i,2,n){
		while(!st0.empty() && a[i] < st0.top() && b[i] < st1.top()){
			st0.pop(); st1.pop();
		}
		if(!st0.empty() && ((a[i] > st0.top() && b[i] < st1.top()) || (a[i] < st0.top() && b[i] > st1.top()))){
			ans = i-1;
			break;
		}
		st0.push(a[i]); st1.push(b[i]);
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%d",&a[i]);
		}
		per(i,1,n){
			scanf("%d",&b[i]);
		}
		solve();
	}
	
	return 0;
}