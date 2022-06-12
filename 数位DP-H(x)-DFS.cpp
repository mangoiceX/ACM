/*
˼·����λdp����Ҫ����״̬ת�Ʋ����롣dp[i][j]��ʾiλ����jС�����ĸ�����
�õݹ���ɵĻ���ֻ��Ҫ˼���߽��״̬ת�ơ�
�߽磺

dp[i][j]���jС��0����Ȼ��dp[i][j]=0�ģ����i==0��˵������0����Ȼ�κ�������0��
����dp[i][j]����j>=0��ʱ��dp[i][j]=1,����dp[i][j]=0��
״̬ת�ƣ�

dp[i][j]+=dp[i-1][j-k*(1<<(i-1))]��
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime> 
using namespace std;
const int maxn = 15;
int dp[maxn][10000];//dp[i][j]��ʾiλ����jС�����ĸ�����
int d[14];			//״̬Ҫ�Һã�֮ǰ���ҵ�״̬��dp[i][j]��ʾiλ��������j�ĸ���
					//�����Ļ��������Ժ��� ,��ʵֻҪС��j�����Թ�Ϊһ�ࣨû������ʱ��
					//��Ϊ����ö�ٵ�����һ���ģ��������������<=j�� 
int a = 0,b = 0;
clock_t st,finish;

int dfs(int pos,int res,bool lim){
	if(pos == 0){
		return res >= 0;
	}
	if(res < 0){
		return 0;
	}
	if(!lim && dp[pos][res] != -1){
		return dp[pos][res];
	}
	int temp = 0;
	int up = lim ? d[pos] : 9;
	for(int i = 0;i <= up;++i){
		///int sum_t = sum + i*pow(2,pos-1);
		int res_t = res - i*(1<<(pos-1));
		if(res_t < 0){//��֦ 
			break;
		}
		temp += dfs(pos-1,res_t,lim && i == d[pos]);
	}
	if(!lim){
		dp[pos][res] = temp;
	}
	return temp;
}
int cal(int x){
	int temp = x;
	int ans = 0,k = 0;
	while(temp > 0){
		ans += (temp % 10) * (1<<(k++));
		temp /= 10;
	}
	return ans;
}
int solve(int x){
	int temp = x;
	int cnt = 0;
	while(temp > 0){
		d[++cnt] = temp % 10;
		temp /= 10;
	}
	d[cnt+1] = 0;
	return dfs(cnt,cal(a),true);
}

void init(){
	memset(dp,-1,sizeof(dp));
}
int main(){
	st = clock();
	int T = 0,kase = 0;
	//freopen("hx.txt","r",stdin);	
	scanf("%d",&T);
	init();//��ʼ������ѭ�����棬�����TLE 
	while(T--){
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",++kase,solve(b));	
	}
	finish = clock();
	printf(" Total time used: %.8lf\n",double(finish - st));
	return 0;
}



