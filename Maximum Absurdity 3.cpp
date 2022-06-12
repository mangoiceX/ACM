#include<bits/stdc++.h>
using namespace std;
#define left left_1
#define right right_1
typedef long long ll;
const int maxn = 2e5+10;
ll n,k,a[maxn],sum[maxn],res[maxn],left[maxn],right[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n-k+1;i++){
        res[i]=sum[i+k-1]-sum[i-1];
//        cout<<i<<" "<<res[i]<<endl;
    }
    int max_pos=1;
    left[1]=1;
    for(int i=2;i<=n-k+1;i++){
        if(res[i]>res[max_pos]) max_pos=i;
        left[i]=max_pos;
    }
    max_pos=n-k+1;
    right[n-k+1]=n-k+1;
    for(int i=n-k;i>=1;i--){
        if(res[i]>=res[max_pos]) max_pos=i;
        right[i]=max_pos;
    }
    int l,r;
    ll max_ans=0;
    for(int i=1;i+k<=n-k+1;i++){
        int j=i+k;
        if(res[left[i]]+res[right[j]]>max_ans){
            max_ans=res[left[i]]+res[right[j]];
            l=left[i],r=right[j];
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}

