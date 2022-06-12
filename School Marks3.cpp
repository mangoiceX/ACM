#include<bits/stdc++.h>
const int maxn = 1010;
int n,p,k,x,y;
int a[maxn];
int ans[maxn];
int main(){
    while (~scanf("%d%d%d%d%d",&n,&p,&k,&x,&y)){
        int s=0,l=0,r=0,cnt=0,i = 0;
        for (i=0;i<p;i++){
            scanf("%d",&a[i]);
            s+=a[i];
            if (a[i]<y) l++; //记录比y小的数有多少
            else if (a[i]>=y) r++;//记录大于等于y的数有多少
        }
        if (l>=n/2+1){  //如果比y小的数超过了一半，那么中位数不可能达到y了
            printf("-1\n");
            continue;
        }
        int xx=n/2+1-r;
        while (xx>0){  //填充右边，尽量填y使得和最小
            ans[cnt++]=y;
            xx--;s+=y;
        }
        xx=n-r-l-cnt;
        while (xx>0)    //填充左边，填1使和尽量小
		{
            ans[cnt++]=1;
            xx--;s++;
        }
        if (s>x){   //和超过x输出-1
            printf("-1\n");
            continue;
        }
        printf("%d",ans[0]);
        for (i=1;i<cnt;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

