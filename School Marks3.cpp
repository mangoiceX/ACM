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
            if (a[i]<y) l++; //��¼��yС�����ж���
            else if (a[i]>=y) r++;//��¼���ڵ���y�����ж���
        }
        if (l>=n/2+1){  //�����yС����������һ�룬��ô��λ�������ܴﵽy��
            printf("-1\n");
            continue;
        }
        int xx=n/2+1-r;
        while (xx>0){  //����ұߣ�������yʹ�ú���С
            ans[cnt++]=y;
            xx--;s+=y;
        }
        xx=n-r-l-cnt;
        while (xx>0)    //�����ߣ���1ʹ�;���С
		{
            ans[cnt++]=1;
            xx--;s++;
        }
        if (s>x){   //�ͳ���x���-1
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

