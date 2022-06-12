#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string> 
#include<cstring>
#include<set>
#include<vector> 
#include<cmath>				//��Ϊ�漰��������ѯ����� �Լ� �޸�ֵ������������Ҫʹ����״���� 
using namespace std;
const int maxn = 1e5 + 10;
int start1[maxn],end1[maxn];//��¼��ʼ����β
bool sign[maxn];
//int sign[maxn];
int tree[maxn];
int n = 0,cnt = 0,m = 0;
vector< vector<int > > at(maxn);//Ԥ����ռ�
 
int lowbit(int x){
	return x & ( -x );
} 

void update(int loc,int val){//������� 
	for(int i = loc;i <= n;i += lowbit(i)){
		tree[i] += val;
	}
}

int get_sum(int loc){//1-loc����ĺ� 
	int sum = 0;
	for(int i = loc;i > 0;i -= lowbit(i)){//i > 0������i >= 0,�����������ѭ�� 
		sum += tree[i];
	}
	return sum;
}

void dfs(int u){//�������䣨���󣬺ܹؼ��� ,ÿ���ڵ�����������������ı���޹� 
	start1[u] = cnt;
	for(int i = 0;i < (int)at[u].size();++i){
		++cnt;
		dfs(at[u][i]);
	}
	end1[u] = cnt;
}

int main(){
	
	while(scanf("%d",&n) != EOF && n){
		at.clear();
		at.resize(maxn);
		
		for(int i = 0;i < n-1;++i){//�����ڽӱ� 
			int u =0,v = 0;
			scanf("%d %d",&u,&v);
			at[u].push_back(v);
		}
		//DFS���� 
		cnt = 1;
		dfs(1);
		//��ʼ�� 
		memset(tree,0,sizeof(tree));
		for(int i = 1;i <= n;++i){
			sign[i] = true;
			//sign[i] = 1;
			update(i,1);
		}
		//���� 
		scanf("%d",&m);
		for(int i = 0;i < m;++i){
			int loc = 0;
			char cmd[10];
			scanf("%s %d",cmd,&loc);
			if(cmd[0] == 'C'){//������� 
				update(start1[loc], sign[loc] == true ? -1 : 1);
				//update(start1[loc], sign[loc] == 1 ? -1 : 1);
				sign[loc] = !(sign[loc]);
				//sign[loc] = 1 - sign[loc];
			}else{//������� 
				printf("%d\n",get_sum(end1[loc]) - get_sum(start1[loc] - 1));
			}
		}
		
	}

	return 0;
}
