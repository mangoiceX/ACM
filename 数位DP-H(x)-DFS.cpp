/*
思路：数位dp。主要在于状态转移不好想。dp[i][j]表示i位数比j小的数的个数。
用递归完成的话就只需要思考边界和状态转移。
边界：

dp[i][j]如果j小于0，显然是dp[i][j]=0的，如果i==0，说明就是0，显然任何数都比0大，
所以dp[i][j]对于j>=0的时候dp[i][j]=1,否则dp[i][j]=0。
状态转移：

dp[i][j]+=dp[i-1][j-k*(1<<(i-1))]；
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime> 
using namespace std;
const int maxn = 15;
int dp[maxn][10000];//dp[i][j]表示i位数比j小的数的个数。
int d[14];			//状态要找好，之前我找的状态是dp[i][j]表示i位数，等于j的个数
					//那样的话可利用性很少 ,其实只要小于j都可以归为一类（没有限制时）
					//因为后面枚举的数是一样的（如果都符合条件<=j） 
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
		if(res_t < 0){//剪枝 
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
	init();//初始化放在循环外面，否则会TLE 
	while(T--){
		scanf("%d %d",&a,&b);
		printf("Case #%d: %d\n",++kase,solve(b));	
	}
	finish = clock();
	printf(" Total time used: %.8lf\n",double(finish - st));
	return 0;
}



