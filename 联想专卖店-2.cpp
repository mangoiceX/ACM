#include <cstdio>
#include <algorithm>
using namespace std;
int T,a,b,c,l,r,mid,ans; 
bool ok(int x,int y,int z){
    if (x>z+y) return 2*(z+y)+1>=mid;
    return z+y+x>=mid;
}

int main(){
    scanf("%d",&T);
    while (T--){
        scanf("%d%d%d",&a,&b,&c);
        l=0,r=min(a,b);
        while (l<=r){
            mid=(l+r)>>1;
            int A=a-mid,B=b-mid,C=c;
            if (ok(max(A,max(B,C)),A+B+C-max(A,max(B,C))-min(A,min(B,C)),min(A,min(B,C)))) l=mid+1,ans=mid;
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
}
