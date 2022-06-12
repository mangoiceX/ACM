#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
#define pi cos(-1)
#define fi first
#define se second
#define pb push_back
#define lson pos<<1
#define rson pos<<1|1
#define lowbit(x) (x&(-x))
#define y1 y_1
#define id(x,y) ((x-1)*m+y)
#define left left_1
#define right right_1
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
map<int, int> mp;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
const ll maxx = 1e6+10;
const ll mod = 1e9+7;
int nxt[maxn],n,m,q;
void getNext(string p)
{
	nxt[0]=-1;
	int plen=p.length();
	int k=-1,j=0;
	while(j<plen)
	{
		//p[k]表示前，p[j]表示后
		if(k==-1||p[j]==p[k])
		{
			k++,j++;
			nxt[j]=k;
		}
		else{
			k=nxt[k];
		}
	}
}
int kmp(string s,string p)
{
	getNext(p);
	int slen=s.length(),plen=p.length();
	int i=0,j=0;
	int ans=0;
	while(i<slen)
	{
		if(j==-1||s[i]==p[j])
		{
			i++,j++;
		}
		else
		{
			j=nxt[j];
		}
		if(j==plen)
		{
//			return i-j;//return 模式串p在文本串s中的位置
			ans++;    //记录模式串出现的次数
//			j=0;//（不重叠）此时重新从j=0开始
          j=nxt[j];    //(重叠)此时j=nxt[j]
		}
	}
//	return -1; //不存在模式串p
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    string s,p,tmp;
    cin>>n>>m>>q;
    cin>>s;
    cin>>p;
    if(m>n){
        for(int l,r,i=1;i<=q;i++){
            cin>>l>>r;
            cout<<0<<endl;
        }
        return 0;
    }
    for(int l,r,i=1;i<=q;i++){
        cin>>l>>r;
        l--,r--;
        tmp.clear();
        for(int i=l;i<=r;i++){
            tmp+=s[i];
        }
        int ans=kmp(tmp,p);
        cout<<ans<<endl;
    }
    return 0;
}

