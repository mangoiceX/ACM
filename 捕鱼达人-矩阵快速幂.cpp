#include<iostream>
#include<cstdio>
#define MOD 1000000000
using namespace std;
typedef long long ll;

ll mod_pow(ll x,ll n,ll mod){
	ll res = 1;
	//x %= mod;
	while(n > 0){
		if( n & 1){
			res = (res * x )% mod;
		}
			n >>= 1;
			x = (x * x) % mod;
	}
	return res;
}

int quick(int a,int b,int c)  //int类型会出错，必须是longlong 
{  
    int ans=1;   //记录结果  
    //a=a%c;   //预处理，使得a处于c的数据范围之下  
    while(b>0)  
    {  
        if(b&1) ans=(ans*a)%c;   //如果b的二进制位不是0，那么我们的结果是要参与运算的  
        b>>=1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位  
        a=(a*a)%c;   //不断的加倍  
    }  
    return ans;  
}  

int main(){
	ll a = 0,p = 0,ans = 0;
	cin >> a >> p; 
	for(ll i = 1 ;i <= a;i++){
		//ans += mod_pow(i,a,p);
		ans = (ans + mod_pow(i,a,p) ) % p;
		//ans = (ans + quick(i,a,p) ) % p;
	}
	
//	ans %= MOD;
	cout << ans << endl;
	//cout << mod_pow(5 ,5,MOD) << endl; 
	
	return 0;
}
