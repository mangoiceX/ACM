#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<set>
#include<queue>
#include<map>
#include<cmath>
#include<string>
#include<cstring>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
const double eps=1.0e-5;
const int maxn=100+ 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,size = 0; 
int a[maxn];
int pre_sum[maxn];
char str[maxn]; 
struct node{
	int val;
	int s,e;
};
node nod[maxn*maxn];
bool cmp1(node a,node b){
	if(a.val != b.val){
		return a.val < b.val;
	}else{
		return a.s < b.s;
	}
}
void solve(){
	int cnt = 0;
	per(i,0,size-1){//��������� 
		per(j,i+1,size){
			nod[++cnt].val = pre_sum[j] - pre_sum[i];
			nod[cnt].s = i + 1;nod[cnt].e = j;
		}
	}
	nod[cnt+1].val = 1e3; 
	sort(nod + 1,nod + cnt + 1,cmp1);//���� 
	for(int i = 1;i <= cnt;){
		if(nod[i].s != 1){//�ҵ���ʼ����Ϊ1�� 
			i++;
			continue;
		}
		int j = i + 1;
		bool flag = false;
		while(nod[j].val == nod[i].val){//�����ֵ������ֻ��һ����ֱ��continue 
			flag = true;
			j++;
		}
		if(flag != true){
			i = j;
			continue;
		}
		int temp = i;
		for(int k = i+1;k <= j-1;++k){
			while(nod[k].s != nod[temp].e + 1 && k <= j - 1){
			//�ҵ���һ����ֵ����������ӵ����䣨��Ϊ��ֵ��������ܻ��ص������Բ����Ǽ��
			//���ڵ����䣬99�������������������WA�� 
				k++;
			}
			if(k > j-1){
				i = j;
				break;
			}
			temp = k;
			if(nod[temp].e == size){
				printf("YES\n");
				return ;
			}
		}
		i = j;//�ǵø�ֵ������������ѭ�� 
	}
	printf("NO\n");
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d",&n)){
		mem(pre_sum,0);
		scanf("%s",str);
		size = 0;//��¼��0���ֵ����� 
		int ct = 0;
		per(i,0,n-1){
			if(str[i] - '0' == 0){//ȥ��0 
				ct++;
				continue;
			}
			a[++size] = str[i] - '0';
			pre_sum[size] = pre_sum[size-1] + a[size];//����ǰ׺�� 
		}
		if(ct == n){//0������������� 
			printf("YES\n");
			continue;
		}
		if(ct == n-1){
			printf("NO\n");
			continue;
		}
		solve();
	}
	
	return 0; 
}
