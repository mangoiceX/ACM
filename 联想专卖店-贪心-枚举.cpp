#include<cstdio>
int T,a,b,c,l,r,mid,ans;
bool ch(int x)
{
    int a1=a,b1=b,c1=c;
    a1-=x;b1-=x;
    if(a1<0||b1<0)
		return 0;
    int mi=a1+b1;
    
    if(a1+c1<mi)
		mi=a1+c1;
    if(b1+c1<mi)
		mi=b1+c1;
    if(mi<x/2)
		return 0;
    return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&a,&b,&c);
        l=0;r=(a+b+c)/3;mid=(l+r)/2;
        while(l+5<r)//����ʱ���Ҽ�࿪��5���ݴ��ʸ�һ��,�������ٽ��������Լ���ʱ�� 
        {
            if(!ch(mid))
				r=mid-1;
            else 
				l=mid;
            mid=(l+r)/2;
        }ans=l;
        for(int i=l;i<=r;i++)//��ʣ�µ�����ɸѡ 
        { 
            if(!ch(i))break;
            ans=i;
        }
        printf("%d\n",ans);
    }
}
