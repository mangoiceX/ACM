/*
�������������ƥ������ 
������õ����������㷨�����䱾����������㷨һ���ģ����õ��Ǻ�Ford-Fulkerson�㷨һ����dfs��
ֻ���������㷨���FF�㷨��·������Դ��s���м�㣬����ȱ���˷���ߣ����з���ߵĽ������ڶ���ƥ������
flow == 0 or == 1,�������㷨ͨ����¼ÿ���ڵ�Ļ���㣬��ʵ�ֺͷ����һ���Ĺ��ܣ� 
�����м�㵽���t������·����
����������·����������㷨�еķ�����Ψһȷ���ģ����Կ���ʡ�ԡ�����FF�㷨ʡ��s,t��Ϊ�������㷨�� 
*/
#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define rep(i,a,b) for(int i = (a);i >= (b);--i)
using namespace std;
const int maxn = 200;
int mp[maxn+10][maxn+10] = {0};//�ڽӾ��� 
int s = 0,t = 200;
int n = 0;
int cx[maxn+10],cy[maxn+10];//cx��ʾx������ƥ���y��cy��ʾy������ƥ���x 
bool vis[maxn+10];
int path(int u){
	per(i,1,84){
		if(!vis[i] && mp[u][i] == 1){
			vis[i] = true;
			if(cy[i] == -1 || path(cy[i])){//���y���ϵ�Ԫ��iû�б�ƥ����ߣ����Դ�cy[i]�ҵ�����· 
				cx[u] = i; cy[i] = u;
				return 1;
			}
		}
	}
}
int max_match(){
	int ans = 0;
	memset(cx,-1,sizeof(cx)); memset(cy,-1,sizeof(cy));
	per(i,1,n){
		//if(cx[i] == -1){//
			memset(vis,false,sizeof(vis));	
			ans += path(i);
		//}
	}
	per(i,1,n){
		printf("%d\n",cx[i]);//���x����ƥ���y 
	}
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		per(i,1,n){
			int k = 0;
			scanf("%d",&k);
			per(j,1,k){	
				int x = 0,y = 0;
				scanf("%d %d",&x,&y);
				mp[i][12*(x-1)+y] =  1;//��ͼ������ߣ�
			}
		}
		int ans = max_match();//���ƥ�� 
		printf("%d\n",ans);
	}
	
	return 0;
} 
/*
5
1 1 1
2 1 1 2 2
1 2 2
2 3 2 3 3
1 3 3
*/
