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
#define inf 0x3f3f3f3f
typedef long long ll;
const double eps=1.0e-5;
const int maxn=200000+10;

int cnt1=0,cnt2=0,cnt3=0,n,tmp,a[maxn],b[maxn],c[maxn],ma=-inf,flag;

int main(){
	//freopen("C:\\Users\\MAC\\Desktop\\in.txt","r",stdin);
	scanf("%d",&n);
	per(i,1,n){
		scanf("%d",&tmp);
		if(tmp<0){
			cnt1++;a[cnt1]=i;
			if(tmp>ma){ma=tmp;flag=i;}//��¼����ֵ��С�ĸ���������λ�� 
		}
		else if(tmp==0) cnt2++,b[cnt2]=i;
		else cnt3++,c[cnt3]=i;
	}
	//ץס���������������������Ĵ�������һ�� 
	per(i,1,cnt3-1) printf("1 %d %d\n",c[i],c[i+1]);
	if(cnt1){//���ڸ��� 
		if(cnt1%2){//��������������Ҫɾ������ֵ��С�ĸ��� 
			per(i,1,cnt1-1){
				if(a[i]==flag) continue;
				if(a[i+1]==flag) a[i+1]=a[i];//��a[i+1]����������ĸ��ǵ� 
				else printf("1 %d %d\n",a[i],a[i+1]);
			}
			per(i,1,cnt2) printf("1 %d %d\n",flag,b[i]),flag=b[i];//0�;���ֵ��С�ĸ����ϲ� 
			if(cnt3>0||cnt1>1)printf("2 %d\n",cnt2?b[cnt2]:flag);//Ȼ������0�ϲ�
			//��������Ǳ�֤���Ľ���Ǵ���0�� 
			//�������Ļ�����ɾ��0(0��flag�ϲ���Ľ��)������ɾ��flag//���������߸�������1�����������ֻ�ش���0 
			if(cnt3 > 0&&cnt1>1) printf("1 %d %d\n",a[cnt1],c[cnt3]);//�����������
			//���Ҹ�������1����ô�Ϳ������߿��Ժϲ� 
			//�����Ǳ�֤���������͸����ϲ���������ϲ� 
		}else{//������ż���� 
			per(i,1,cnt2-1) printf("1 %d %d\n",b[i],b[i+1]);//����0 
			per(i,1,cnt1-1) printf("1 %d %d\n",a[i],a[i+1]);//������ 
			if(cnt2) printf("2 %d\n",b[cnt2]);//ɾ��0 
			if(cnt3) printf("1 %d %d\n",a[cnt1],c[cnt3]);//�����������յĸ����ϲ� 
		}
	}else{//û�и��� 
		per(i,1,cnt2-1) printf("1 %d %d\n",b[i],b[i+1]);//����0 
		if(cnt2&&cnt3) printf("2 %d\n",b[cnt2]);//�����0����������������ôɾ��0 
	}
	return 0;
}
