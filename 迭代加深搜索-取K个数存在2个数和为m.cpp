/*
��n����ͬ����������A������m����A������ȡ��k�����������б�����������֮�͵���m��
��k����Сֵ����д���򲢴�ӡ���
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int A[maxn+10];
int n = 0,m = 0;
int maxd = 0;
bool check(int *a){//����maxd�����Ƿ�����������Ϊm 
	map<int,int> mp;
	int cnt = 0;
	bool flag = (m % 2 == 0 ? true : false);//m�����������⴦��û��m/2,��Ϊ/�ǵذ�� 
	for(int i = 1;i <= maxd;++i){
		mp[a[i]] = 1;
		if(a[i] == m/2){
			++cnt;
		}
	}
	if(cnt >= 2 && flag){//ע��a[i] == m/2�����,mҪ��ż�����ر��� 
		return true;
	}
	for(int i = 1;i <= maxd;++i){
		if(flag == true && a[i] == m/2){//ע��a[i] == m/2�����,�ر���
			continue;
		}
		if(mp.find(m-a[i]) != mp.end()){//ע��a[i] == m/2����� 
		//if(a[i] != m/2 && mp.count(m-a[i]) == 1){
			return true;
		}
	}
	return false;
}
bool dfs(int depth,int* ans,int cnt){
	if(depth == n){//û��maxd������������Ҫ�� 
		if(cnt < maxd){
			return true;
		}
	}
	if(cnt == maxd){//ѡ��maxd���������� 
		return check(ans);
	}
	//if(cnt + n - depth < maxd){//�����뻯��֦����ʱ�������ȫ��ѡ��Ҳ�޷�ѡ���maxd���� 
	//	return true;
	//}
	ans[cnt+1] = A[depth+1];
	if(dfs(depth+1,ans,cnt+1) == false){//ֻҪ��һ����ϲ�����Ҫ���һֱ����false 
		return false;
	}
	if(dfs(depth+1,ans,cnt) == false){//��ѡ������� 
		return false;	
	}
	return true;//������϶�����Ҫ�󣬾ͷ���true 
}
int main(){ 
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;++i){
			scanf("%d",&A[i]);
		}
		scanf("%d",&m);
		sort(A+1,A+1+n);
		bool flag = false;
		int ans[maxn+10];
		for(maxd = 2;maxd <= n;++maxd){//������������ 
			if(dfs(0,ans,0)){
				printf("%d\n",maxd);
				flag = true;
				break;
			}
		
		}
		if(flag == false){
			printf("There is no answer!!!\n");
		}
	}
	
	return 0;
}
