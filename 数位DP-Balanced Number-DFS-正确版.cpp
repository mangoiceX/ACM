#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
LL dp[25][25][2500];//��״̬��̫��Ҫ�� 
//dp[i][j][k],f(i,j,k)��ʾiλ����֧��j�����ߺ�λk�����Ϊ�����ұ�Ϊ���� 
//ö��j��ע���ȥ0���������Ϊ0��Ψһһ�����Ա�֧����Ȼ�������� 
int d[25];
LL dfs(int pos,int mid,int sum,bool uplim){
	if(sum < 0){//��֦����ǰ�˳�,sum<0ʱ,��ʾ�ұߵĺʹ�������� 
		return 0;//���������ԣ�ֻ�ü�¼һ��ֵsum���ɣ������ü�¼l_sum��r_sum,֮ǰ�Ҿ��������� 
	}
	if(pos <= 0){
		return sum == 0;
	}
	if(!uplim && dp[pos][mid][sum] != -1){
		return dp[pos][mid][sum];
	}
	LL temp = 0;
	int up = uplim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		temp += dfs(pos-1,mid,sum + i*(pos-mid),uplim && i == d[pos]);
	}
	if(!uplim){
		dp[pos][mid][sum] = temp;
	}
	return temp;
}
LL solve(LL x){//ע��l==0ʱ����� 
	//if(x < 0){
	//	return 0;
	//}
	LL temp = x;
	int cnt = 0;
	while(temp != 0){//֮ǰ��temp > 0,����������-1,��l==0ʱ����� 
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	LL ans = 0;
	for(int mid = 1;mid <= cnt;++mid){//
		ans += dfs(cnt,mid,0,true);
	}
	ans -= (cnt - 1);//��ȥ00,000,0000����� 
	return ans;
}

void init(){
	memset(dp,-1,sizeof(dp));
}

int main(){
	int T = 0;
	LL l = 0,r = 0;
	cin >> T;
	init();
	while(T--){
		cin >> l >> r;
		cout << solve(r) - solve(l-1) << endl;
	}
	return 0;
}
