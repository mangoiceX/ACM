#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
typedef unsigned long long LL;
const int maxn = 100 + 5;
LL data[maxn];
LL ans[maxn];
bool vis[maxn];
int flag = 0;
//vector< vector<LL> > adj(maxn);
vector<int> adj[maxn];		//�����ڽӱ� 
int n = 0;
void dfs(int loc,int cur){
	if(cur == n){
		flag = 1;
		for(int i = 0;i < n;++i){
			if(i != 0){
				cout << " ";
			}
			cout << ans[i];
		}
		cout << endl;
		return ;
	}
	vis[loc] = 1;
	for(size_t i = 0;i < adj[loc].size();++i){
		if(vis[adj[loc][i]] == 0){
			vis[adj[loc][i]] = 1;
			
			ans[cur] = data[adj[loc][i]];
			dfs(adj[loc][i],cur + 1);
			
			vis[adj[loc][i]] = 0;//�ǵû�ԭ���� 
		}
	}
}
int main(){
	
	std::ios::sync_with_stdio(false); //���cin,cout���ٶȣ�ʹ����Ч���ӽ�scanf,printf
	// ʹ����ͬ��stream��������ȱʡֵ��ͬ�� ��ʹ�øú�����ȡ��ͬ�� 
  	flag = 0;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> data[i];
	}
	
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j){//״̬����������������ʱ������һ������� 
			if(data[j] == 2* data[i] || data[i] == 3*data[j]){ //��������� 
				adj[i].push_back(j);//���յ�һ���𰸾������ѱ�������ͼ���� 
			}
		}
	}
	
	for(int i = 0;i < n;++i){
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		ans[0] = data[i];//��һ������� 
		dfs(i,1);
		if(flag == 1){//�����һ������������Ա���������ͼ��������˳� 
			break;
		}
	}
	
	
	return 0;
}

