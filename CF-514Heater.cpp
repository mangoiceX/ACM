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

//#define pii pair<int, int>
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define per(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define PER(i,x) for(auto i=x.begin();i!=x.end();i++)
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef pair<int,int> pii;
const double eps=1.0e-5;
const int maxn=1e3 + 10;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n = 0,r = 0; 
int a[maxn],pos[maxn];
bool vis[maxn];
void solve(){
	fill(vis,vis+maxn,false);

	int ans = 0,fg = 0,flag = 0;
	for(int i = 1;i <= n;){
		fg = 0;
		for(int j = max(i-1,1);j >= max(i-r+1,1);--j){//���ȱ����õ�ǰ��ĵ��Ƿ���heater 
			if(vis[j] == true){	//����У�i++,���¿�ʼ 
				i++;
				fg = 1;
				break;
			}
		}
		if(fg == 1){
			continue;
		}
		for(int j = min(i+r-1,n);j >= i+1;--j){//Ȼ������ĺ�����heater������Զ�ĵط���ʼ��	
			if(a[j] == 0 ){//0ֱ������ 
				continue;
			}
			if(vis[j] == true){//�ҵ�һ��heater,������j+r 
				i = j + r-1+1;
				fg = 1;
				break;
			}
			if(vis[j] == false){//�ҵ�һ��û����1����ô�ʹ� 
				ans++;
				vis[j] = true;
				i = j + r-1+1;
				fg = 1;
				break;
			}
		}
		if(fg == 1){
			continue;
		}
		//�����벿��û���ҵ�����ֻ��ȥǰ���1�� 
		for(int j = max(i-1,1);j >= i-r+1 && j >= 1;--j){
			if(a[j] == 0){
				continue;
			}
			if(vis[j] == true){//�ҵ�һ���Ѿ��򿪵ģ������� 
				i = j + r-1+1;
				fg = 1;
				break;
			}
			if(vis[j] == false && a[i] != 1){//�ҵ�һ��û����1�����Ǳ�������1��
			//��Ϊ������1�Ļ� ������㿪�����Ͳ���ǰ���1�� 
				ans++;
				vis[j] = true;
				i = j + r-1+1;
				fg = 1;
				break;
			}
		}
		if(a[i] == 1 && fg == 0){//�������û���ҵ�1������ǰ��û���Ѿ��򿪵�1, 
			ans++;//��ô�ʹ򿪱����1 
			vis[i] = true;
			i++;
			fg = 1;
			continue;
		}
		if(fg == 0){//������Ҳ�������ô���ﲻ�ܱ�heat 
			flag = 1;
			break;
		}
	}
	printf("%d\n",flag == 1 ? -1 : ans);
}
int main(){
	#ifndef ONLINE_JUDGE
		//freopen("a.txt","r",stdin);
	#endif
	while(~scanf("%d %d",&n,&r)){
		per(i,1,n){
			scanf("%d",&a[i]);
		} 
		solve();
	}
	
	return 0; 
}
