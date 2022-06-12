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

int quick(int a,int b,int c)  //int���ͻ����������longlong 
{  
    int ans=1;   //��¼���  
    //a=a%c;   //Ԥ����ʹ��a����c�����ݷ�Χ֮��  
    while(b>0)  
    {  
        if(b&1) ans=(ans*a)%c;   //���b�Ķ�����λ����0����ô���ǵĽ����Ҫ���������  
        b>>=1;    //�����Ƶ���λ�������൱��ÿ�γ���2���ö����ƿ����������ǲ��ϵı���b�Ķ�����λ  
        a=(a*a)%c;   //���ϵļӱ�  
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
