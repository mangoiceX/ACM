#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e3 + 100;
typedef unsigned long long LL;
int f[maxn*maxn];
LL a = 0,b = 0;
int n = 0,mod = 0;
int T = 0;
void pre_solve(){
	for(int i = 2;i < n * n + 100;++i){
		f[i] = (f[i-1] + f[i-2]) % n;
		if(f[i] == f[1] && f[i-1] == f[0]){
			mod = i - 1;//周期循环规律，像这样数据规模很大的，很可能存在某种规律 
			break;//不妨打印几个例子观察一下规律 
		}
		//mod = 2;
	}
	//mod = n * n + 101;
}
LL solve(){
	LL ans = 1;
	a = a % mod;
	while(b > 0){
		if(b & 1){
			ans =  (a % mod )* (ans % mod) % mod; 
			//ans = (a % mod) * ans % mod;
		}
		a = (a % mod) * (a % mod) % mod ;
		//a = a % mod * a;
		b >>= 1;
	}
	return ans;
}
LL mod_pow(LL x,LL n){//学会自己推导递归式，有点抽象 
	if(n == 0){//终止条件 
		return 1;
	}
	LL res = mod_pow((x % mod) * (x % mod) % mod ,n / 2);//递归表达式 
	if(n & 1){//偶数递归下去除以2，奇数的1，要添加 
		res = (res % mod) * (x % mod) % mod;
	}
	return res;
}
LL mod_pow1(LL a, LL p,LL mod) {
	if(p == 0) return 1;
	LL ans = mod_pow1(a, p/2,mod);
	ans = ans * ans % n;
	if(p%2 == 1) ans = ans * a % n;
	return ans;
} 
int main(){
	f[0] = 0; f[1] = 1;
	//scanf("%d",&T);
	cin >> T;
	while(T--){
		//scanf("%I64d %I64d %d",&a,&b,&n);
		cin >> a >> b >> n;
		if(n == 1){
			cout << "0" << endl;
			continue; 
		}
		pre_solve();
		//int ans = (int)mod_pow1(a % mod,b,(LL)mod);
		//int ans = solve();
		int ans = mod_pow(a,b);
		//printf("%d\n",f[ans]);
		cout << f[ans] << endl;
	}
	
	return 0;
} 
