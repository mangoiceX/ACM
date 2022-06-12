// #include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
const int maxn = 1e3 + 10;
const int mod = 6;
int n = 0,k = 0;
int A[maxn][10],B[10][maxn];
int ans[maxn][maxn];
struct Matrix{
	int a[10][10];
	int si;
	Matrix(){}
	Matrix operator * (const Matrix &b)const{
		Matrix res;
		res.si = si;
		memset(res.a,0,sizeof(res.a));
		per(i,1,si){
			per(j,1,si){
				per(l,1,si){
					res.a[i][j] = (res.a[i][j] + this->a[i][l] * b.a[l][j]) % mod;
				}
			}
		}
		return res;
	}
};

Matrix q_power(Matrix M,int y){
	Matrix res;
	memset(res.a,0,sizeof(res.a));
	per(i,1,k){
		res.a[i][i] = 1;
	}
	res.si = k;
	while(y > 0){
		if(y & 1){
			res = res*M;
		}
		M = M*M;
		y >>= 1;
	}
	return res;
}
int main(){
	// cout << "ji" << endl;
	// printf("jifda\n");
	// while(scanf("%d %d",&n,&k) && n && k){
	while (~scanf("%d %d", &n, &k) && (n || k)){
		per(i,1,n){
			per(j,1,k){
				scanf("%d",&A[i][j]);
			}
		}
		per(i,1,k){
			per(j,1,n){
				scanf("%d",&B[i][j]);
			}
		}
		Matrix base;
		base.si = k;
		memset(base.a,0,sizeof(base.a));
		per(i,1,k){
			per(j,1,k){
				per(l,1,n){
					base.a[i][j] = (base.a[i][j] + B[i][l] * A[l][j]) % mod;
				}
			}
		}

		base = q_power(base,n*n-1);

		int b1[maxn][10];
		memset(b1,0,sizeof(b1));
		per(i,1,n){
			per(j,1,k){
				per(l,1,k){			
					b1[i][j] = (b1[i][j] + A[i][l] * base.a[l][j]) % mod;
				}
			}
		}

		
		memset(ans,0,sizeof(ans));
		per(i,1,n){
			per(j,1,n){
				per(l,1,k){
					ans[i][j] = (ans[i][j] + b1[i][l] * B[l][j]) % mod;
				}
			}
		}
		int sum = 0;
		per(i,1,n){
			per(j,1,n){
				sum += ans[i][j];
			}
		}
		printf("%d\n",sum);

	}


	return 0;
}