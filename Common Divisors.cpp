#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
const int maxn = 4e5 + 10;
int n = 0,m = 0;
LL a[maxn];
LL gcd(LL x,LL y){
	return y == 0 ? x : gcd(y,x%y);
}

// long long eular(long long n)
// {
//     long long ans = n;
//     for(int i = 2; i*i <= n; i++)
//     {
//         if(n % i == 0)
//         {
//             ans -= ans/i; //等价于通项，把n乘进去
//             while(n % i == 0) //确保下一个i是n的素因数
//                 n /= i;
//         }
//     }
//     if(n > 1)ans -= ans/n; //最后可能还剩下一个素因数没有除
//     return ans;
// }

int main(){
	while(~scanf("%d",&n)){
		per(i,1,n){
			scanf("%I64d",&a[i]);
		}
		LL gc = 0;
		if(n == 1){
			gc = a[1];
		}else{
			gc = gcd(a[1],a[2]);
		}
		per(i,3,n){
			gc = gcd(gc,a[i]);
		}
		// cout<< gc << endl;
		// LL ans = eular(gc);
		// printf("%I64d\n",ans);
		int ans = 0;
		map<LL,int> mp;
		LL i = 1;
		for(i = 1;i* i < gc;++i){
			// while(gc % i == 0){
			// 	++mp[i];
			// 	gc /= i;
			// }
			if(gc % i == 0){
				ans += 2;
			}
		}
		if(i * i == gc){
			ans += 1;
		}
		printf("%d\n",ans);
		// map<int,int>::iterator it = mp.begin();
		// LL ans = 1;
		// for(it = it;it != mp.end();++it){
		// 	ans *= 
		// }
	}

	return 0;
}
