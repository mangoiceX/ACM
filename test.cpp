#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
LL x0 = 0,x1 = 0,a = 0,b = 0;
LL mod = 0;
struct Matrix{
    LL num[2][2];
    int si;
    Matrix(){}
    Matrix operator * (const Matrix &b)const{
        Matrix res;
        res.si = si;
        memset(res.num,0,sizeof(res.num));
        per(i,0,1){
            per(j,0,1){
                per(l,0,1){
                    res.num[i][j] = (res.num[i][j] + this->num[i][l] * b.num[l][j]) % mod;
                }
            }
        }
        return res;
    }
    Matrix operator % (LL mod)const{
        Matrix res;
        res.si = si;
        // memset(res.num,0,sizeof(res.num));
        per(i,0,1){
            per(j,0,1){
                res.num[i][j] = this->num[i][j] % mod;
            }
        }
        return res;
    }

};

Matrix quick_mod(Matrix a,long long b){
    Matrix ans;
    per(i,0,1){
        per(j,0,1){
            ans.num[i][j] = 1;
        }
    } 
    while(b){
        if(b&1){
            ans=(ans*a)%mod;
            b--;
        }
        b/=2;
        a=a*a%mod;
    }
    return ans;
}//内部也用快速幂
Matrix quickmod(Matrix a,char *b,int len){
    Matrix ans;
    per(i,0,1){
        per(j,0,1){
            ans.num[i][j] = 1;
        }
    }
    while(len>0){
        if(b[len-1] != '0'){
            int s=b[len-1]-'0';
            ans=ans*quick_mod(a,s)%mod;
        }
        a=quick_mod(a,10)%mod;
        len--;
    }
    return ans;
}
 
int main(){
    char n[1000050];
    //求a^s%mod
    scanf("%lld %lld %lld %lld",&x0,&x1,&a,&b);
    scanf("%s",n);
    scanf("%lld",&mod);
    int len =strlen(n);
    Matrix ma;

    ma.num[0][0] = a; ma.num[1][0] = b; ma.num[0][1] = 1; ma.num[1][1] = 0;
    Matrix ans =  quickmod(ma,n,len);
    printf("%lld %lld %lld %lld\n",ans.num[0][0],ans.num[0][1],ans.num[1][0],ans.num[1][1]);
    printf("%lld\n",(ans.num[0][0]+ ans.num[1][0])* x1 % mod);

    return 0;
}
 