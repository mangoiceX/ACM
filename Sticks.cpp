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
bool vis[maxn];
int data[maxn];
int n = 0;

bool dfs(int pos,int res,int len){
	if(pos == 0 && res == 0){//ȫ��ƴ�ӳɹ� 
		return true;
	}
	if(pos != 0 && res == 0){//һ��ƴ�ӳɹ� 
		res = len;
	}
	for(int i = n - 1;i >= 0;--i){//��ƴ���ģ������������ƴ�̵��� 
		if(vis[i] == 0 && data[i] <= res){
			vis[i] = 1;
			if(dfs(pos - 1,res - data[i],len)){
				return true;
			}
			vis[i] = 0;
			//���Ǿ����Եļ�֦ 
			if(vis[i - 1] == 0 && data[i - 1] == data[i]){//�������һ������һ��������ƴ�ˣ�restart 
				continue;
			}
			//�����Լ�֦ ��������ͬ�����ظ����ԡ� 
			if(res == data[i] || res == len){//ʣ�µĸպ�ƴ��һ�����ӣ����Ƕ�û�гɹ�
			//��ʹ�����ø��̵Ķ�����������Ҳ�޷��ɹ��������ڴ˴�ֱ���ж����ڵ�ƴ��ûǰ;��restart
			//��Ϊ��ʹ���̹������������ƴ����ʱ������Ҫ�õ�
			//����len = 10,data[i]=5�����Ա������3+2ȡ�������Ǻ���Ҫ�ɹ��Ļ�������Ҫ��x+5=10��
			//����5��������õ�����������ƴ���Ľ����һ����
			 
				return false;
			}
		}
	}
	return false;
	
}
/*
bool dfs(int pos, int res, int len) {
	if (pos == 0 && res == 0)
		return true;
	if (res == 0)
		res = len;
	for (int i = n - 1; i >= 0; i--){
		if (vis[i] || data[i] > res)
			continue;
		vis[i] = true;
		if (dfs(pos - 1, res - data[i], len))
			return true;
		vis[i] = false;
		if (res == data[i] || res == len)//��Ҫ�ļ�֦��������ͬ�����ظ����ԡ�
			return false;
	}
	return false;
}
*/
int main(){
	std::ios::sync_with_stdio(false);
	while(cin >> n && n){
		
		for(int i = 0;i < n;++i){
			cin >> data[i];
		}
		
		sort(data,data + n);
		int sum = 0;
		
		for(int i = 0;i < n;++i){
			sum += data[i]; 
		}
		int  i = 0;
		for(i = data[n - 1]; i <= sum / 2;++i){//ȷ��������Χ 
			memset(vis,0,sizeof(vis));
			if(sum % i != 0){
				continue;
			}
			if(dfs(n,i,i)){
				cout << i << endl;
				break;
			}
		}
		if(i > sum / 2){
			cout << sum << endl;
		}
	}
	
	
	
	return 0;
} 
