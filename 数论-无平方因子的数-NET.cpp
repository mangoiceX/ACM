#include<iostream> 
#include<cstdio>
#include<cmath>
bool vis[10000005];
int sums(int x,int y){
	int sum=0;
	int m=(int)sqrt(y+0.5);//精度有时候会抽风，这样保险一点
	for(int i=2;i<=m;i++)
		for(int j=x/i/i;j*i*i<=y;j++)//注意，j从x（首端）/i/i开始,就是x/(i^2)，作用是计算第一个大于首端的含i^2因子的数，是i^2的几倍
			if(j*i*i>=x)//，因为是向下取整的缘，故为了保险，再判断一次，因为一旦不属于该区间的数被改动了，就会有重复的问题
				vis[j*i*i%(y-x+1)+1]=1;//mod长度，注意不能减去，因为会减成负数，就运行错误了
	for(int i=1;i<=y-x+1;i++)
		if(!vis[i])
			sum++;//找没有被更新（筛）到的数
	return sum;
}
int main(){
	int n = 0,m = 0;
	scanf("%d%d",&n,&m);
	printf("%d",sums(n,m));//输入输出
}

