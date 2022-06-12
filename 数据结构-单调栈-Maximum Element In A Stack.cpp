#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cmath>

using namespace std;

#define pii pair<int, int>
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
#define pi acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
#define uu unsigned
const double eps=1.0e-5;
const int maxn=2e5;
const LL mod=1e9+7;
struct node{
	int val,id;
};
stack<node> st1;
stack<int> st2;
int n = 0,p = 0,q = 0,m = 0;
unsigned int SA,SB,SC;
uu rng61(){
    uu t;
    SA^=SA<<16;
    SA^=SA>>5;
    SA^=SA<<1;
    t=SA,SA=SB,SB=SC,SC^=t^SA;
    return SC;
}
LL gen(){
    while(!st1.empty()){
    	st1.pop();
    }
    while(!st2.empty()){
    	st2.pop();
    }
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    LL ans = 0,res = 0;
    per(i,1,n){
    	if(rng61() % (p + q) < p){
    		res = LL(rng61() % m) + 1;
    		if(st1.empty() || st1.top().val < res){//只有当前值比栈顶元素大，或者栈为空，才入栈
    			st1.push(node{res,i});
    		}
			st2.push(i);
    	}else{
    		if(!st2.empty()){//如果栈没有元素，此时pop(),会有问题
    			if(!st1.empty() && st1.top().id == st2.top()){
					st1.pop();
				}
				st2.pop();
    		}
		}
		if(!st1.empty()){//栈里面没有元素则为0，不用操作
			ans ^= (1ll*i*st1.top().val);
		}
    }
    return ans;
}

int main(){
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);cout.tie(0);
	int T = 0;
	scanf("%d",&T);
	per(i,1,T){
		printf("Case #%d: %lld\n",i,gen());
	}
	return 0;
}
