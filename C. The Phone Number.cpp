#include<bits/stdc++.h>
#define LL long long 
using namespace std;
int const mod=1e9+7;
int const maxn=2e5+10;
int a[maxn],sum[20],b[maxn];
int get(int a[],int n) {
    memset(sum,0,sizeof(sum));
    int ans=1,mi=1;
    for (int i=1;i<=n;i++) {
        sum[i]=1;
        for (int j=1;j<i;j++) {
            if (a[i]>a[j]) {
                sum[i]=max(sum[i],sum[j]+1);
                ans=max(ans,sum[i]);
            }
        }
    }
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=n;i++) {
        sum[i]=1;
        for (int j=1;j<i;j++) {
            if (a[i]<a[j]) {
                sum[i]=max(sum[i],sum[j]+1);
                mi=max(mi,sum[i]);
            }
        }
    }
    return ans+mi;
}
int main() {
    int n;
    cin>>n;
        int k=sqrt(n);

        int now=0;
        for (int i=1;i<=n;i+=k) {
            now=min(n,i+k-1);
            for (int j=0;j<k;j++) {
                a[i+j]=now-j;
            }
        }
    for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;

}
