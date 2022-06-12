#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#define LOCAL
using namespace std;
typedef long long LL;

LL dp[20][2530][60];//����״̬dp[i][j][k]����iλ����������µõ���������λ�����ֵ���С������Ϊj
//��ÿ����λ�ϵ�����֮��%2520Ϊk�ķ�������
int d[20],hush[2530];
LL GCD( LL x,LL y ){//�ݹ飬շת����� 
	if(y == 0){
		return x;
	}
	return GCD(y,x%y);
} 
LL LCM(LL x,LL y){
	//return x * y / GCD(x,y);
	return x / GCD(x,y) * y;//�ȳ��ٳˣ���ֹ��� 
}
LL dfs(int pos,LL mod,LL lcm,bool uplimited){
	if(pos <= 0){
		return (mod % lcm) == 0;
	}
	if(!uplimited && dp[pos][mod][hush[lcm] ] != -1){
		return dp[pos][mod][hush[lcm] ];
	}
	LL temp = 0;
	int up = uplimited ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		LL mod_t = (mod * 10 + i ) % 2520;
		LL lcm_t = (i == 0) ? lcm : LCM(i,lcm);
		temp += dfs(pos - 1,mod_t,lcm_t, uplimited && i == d[pos]);
	} 
	if(!uplimited){
		dp[pos][mod][hush[lcm] ] = temp;
	}
	return temp;
}
LL solve(LL x){
	LL temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,0,1,true);
}
void init(){
	memset(dp,-1,sizeof(dp));
	int a = 0;
	for(int i = 1;i * i< 2520;++i){//��2520�����ӽ���hush���棨ѹ���� 
		if(2520 % i == 0){
			hush[i] = a++;
			hush[2520/i] = a++;
		}
	}
	
}
int main(){
	#ifdef LOCAL
		freopen("a.txt","r",stdin);
	#endif
	int T = 0;
	LL l = 0,r = 0;	
	cin >> T;
	init();
	while(T--){
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << endl;
	}
	
	return 0;
} 
