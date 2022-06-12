#include<bits/stdc++.h>
#define fi first
#define se second 
#define mk make_pair
#define pb push_back
#define P pair<ll,ll>
#define INF 0x3f3f3f3f
#define mod 1000000007
#define lowbit(n) n&-n
#define mem(i) memset(i,0,sizeof(i))
#define bcnt(x) __builtin_popcount(x)
#define bcntz(x) __builtin_ctz(x)
using namespace std;
const int maxn=100010;
typedef long long ll;
typedef long double ld; 
int n,m;
int gi(){
    char a=getchar();int b=0;
    while(a<'0'||a>'9')a=getchar();
    while(a>='0'&&a<='9')b=b*10+a-'0',a=getchar();
    return b;
}

ll t[maxn],yu[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;scanf("%d",&T);
    while(T--){
        priority_queue<ll> Q;
        ll k;
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%lld",&t[i]);
        }
        sort(t+1,t+n+1);
        ll ans=k;
        int sum=1;
        for(int i=n;i>=1;i--){
            sum--;
            if(i==1){
                ans+=t[i];
                break;
            }
            ans+=(t[i]/k)*k;
            yu[i]=t[i]%k;
            sum+=t[i]/k;
            if(sum==0){
                if(Q.empty()){
                    ans+=k;
                    sum++;
                }else{
                    ll tt=Q.top();
                    if(k-tt<k-yu[i]){
                        Q.pop();
                        ans-=tt;
                        ans+=k,sum++;
                        ans+=yu[i];
                        Q.push(yu[i]);
                    }
                    else ans+=k,sum++;
                }
            }
            else{
                ans+=yu[i];
                Q.push(yu[i]);
            }
            
        }
        
        printf("%lld\n",ans);
        
        
    }
    return 0;   
    
}