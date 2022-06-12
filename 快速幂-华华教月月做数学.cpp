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

typedef unsigned long long LL;

#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i = a;i <= b;++i)
#define rep(i,a,b) for(int i = a;i >= b;--i)
const int maxn = 3e5;
LL a = 0,b = 0,p = 0; 
_int128 ans = 0;
LL q_pow1(){
	ans = 1;
	//a %= p,b%= p;
	while(b > 0){
		if(b&1){
			ans = ans * a % p;
		}
		//cout << "niam " << ans << " " << a << endl;
		//a = ((a%p)*(a%p))%p;
		a = a*a%p;
		b >>= 1;
	}
	return ans;
}
void print(__int128 x) {  
    if(!x){  
        puts("0");  
        return ;  
    }  
    string ret="";  
    while(x){  
        ret+=x%10+'0';  
        x/=10;  
    }  
    reverse(ret.begin(),ret.end());  
    cout<<ret<<endl;  
}
int main(){
	//std::ios::sync_with_stdio(false);
	
	int T = 0;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld",&a,&b,&p);
		//printf("%lld\n",q_pow1());
		print(ans);
	}
	
	return 0;
}
