#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
#define INF 1e18
using namespace std;
typedef long long LL;
LL x0 = 0,x1 = 0,a = 0,b = 0;
const int maxn = 1e6 + 10;
char s[maxn];

LL mod = 1e9 + 7;
struct Matrix{
	LL num[2][2];
	Matrix(){
		memset(num,0,sizeof(num));
	}
	Matrix operator * (const Matrix& M)const{
		Matrix ans;
		// memset(ans.num,0,sizeof(ans.num));
		per(i,0,1){
			per(j,0,1){
				per(l,0,1){
					ans.num[i][j] = (ans.num[i][j] + this->num[i][l] * M.num[l][j]) % mod;
				}
			}
		}
		return ans;
	}
};
Matrix ma[maxn];
Matrix q_power(Matrix M,LL p){//矩阵快速幂
	Matrix ans;
	per(i,0,1){
		ans.num[i][i] = 1;
	}
	while(p > 0ll){
		if(p & 1ll){
			ans = ans*M;
		}
		M = M*M;
		p >>= 1;
	}
	return ans;
}
int main(){
	scanf("%lld %lld %lld %lld",&x0,&x1,&a,&b);
	scanf("%s",s); scanf("%lld",&mod);
	
	int len = strlen(s);
	ma[0].num[0][0] = a; ma[0].num[1][0] = b;ma[0].num[0][1] = 1;ma[0].num[1][1] = 0;

	const int LEN = 8;//预处理
	for(int i = LEN;i <= 1e6+1;i += LEN){//以8为间隔，预处理，算出基底
		ma[i] = q_power(ma[i-LEN],100000000ll);
	}
	Matrix ans;	
	per(i,0,1){//单位矩阵，与任何矩阵相乘结果不变
		ans.num[i][i] = 1;
	}
	for(int i = len-1;i >= 0;i -= LEN){
		LL num = 0;
		for(int j = 0,k=1;j < LEN;++j,k *= 10){
			if(i - j < 0){
				break;
			}
			num = num + (s[i-j] - '0')*k;
		}
		if(num == 0){
			continue;
		}
		ans = ans*q_power(ma[len-1-i],num);//相当于基底的num次幂
	}
	Matrix bas;
	bas.num[0][0] = x1; bas.num[0][1] = x0; bas.num[1][0] = 0; bas.num[1][1] = 0;
	bas  = bas*ans;
	printf("%lld\n",bas.num[0][1]);

	return 0;
}