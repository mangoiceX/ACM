#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define mem(a) memset(a,0,sizeof(a))
using namespace std; 
const int maxn = 1e5 + 10;

string opr[maxn];

bool vis[maxn];
bool flag[maxn];//��ǵ�һ�γ��ֵķ��� 
int num[maxn];
int res[maxn];
int main(){
	int n = 0,m = 0,leader = 0;
	int exist = 1,loc = 0;//exist����û��-�õı�ǣ�loc�����һ���״γ��ֵ���"-"������λ�� 
	string opr;
	while(cin >> n >> m){
		
	
	mem(vis);
	memset(flag,0,sizeof(flag)); 
	for(int i = 1;i <= m;++i){
		cin >> opr[i] >> num[i];
		if(opr[1] == '+'){
			if(opr[i] == '-' && flag[num[i]] == 0){//����ͳ�Ƴ����һ����һ�γ��ֵ���"-"�ŵ��� 
				loc = i;
				leader = num[i];
				
			}
			flag[num[i]] ++;
			vis[num[i]] = 1;
			if(num[i] == num[1] && i != m){//�жϵ�һ���Ӻ� 
				exist = 0;
			}
		}else{
			exist = 0;
			if(opr[i] == '-' && flag[num[i]] == 0){//����ͳ�Ƴ����һ����һ�γ��ֵ���"-"�ŵ���
				loc = i;
				leader = num[i];
				
			}
			flag[num[i]] ++;
			vis[num[i]] = 1;
		}
		
	}
	if(leader != 0 && opr[loc + 1] == '+' && num[loc + 1] == leader){
	//���һ��"-"����һ��������"+"leader 
		vis[leader] = 0;
	}else if(exist == 1){
		vis[num[1]] = 0;
	}
	int ans = 0,k = 1;
	for(int i = 1;i <= n;++i){
		if(vis[i] == 0){
			res[k++] = i;
			++ans;
		}
	}
	cout << ans << endl;
	for(int i = 1;i <= k;++i){
		if(i > 1){
			cout << " ";
		}
		cout << res[i];
	}
	cout << endl;
}
	return 0;
}
