#include<iostream>
#include<cstdio>
using namespace std;
char t[200005];
int nex[200005],sum1[200005];
void get_next()               //����nextֵ 
{
    int i,j;
    i=0;
    j=-1;
    nex[0]=-1;
    while(t[i])
    {
         if(j==-1||t[i]==t[j])
         {
            ++i;
            ++j;
            nex[i]=j;
         }
         else
            j=nex[j];
    }   
}

int main(){
    int i,n,m,sum2;
    scanf("%d",&n);
    while(n--){
        for(i=0;i<200005;i++)
        sum1[i]=0;
        sum2=0;   
        scanf("%d ",&m);
        scanf("%s",t);
        get_next();
        for(i=1;i<=m;i++)                            //��Ϊnextֵ�Ǵ�-1��ʼ��,�������μ�1 
            sum1[nex[i]]=(sum1[nex[i]]+1)%10007;
        for(int i = 1;i <= m;++i){
        	cout << sum1[i] << " ";
		}
		cout << endl;
        for(i=1;i<=m;i++)                             //��Ϊnext����Ϊ�������������Ӵ�����,����Ҫ��1,������ 
            sum2=(sum2+sum1[i]+1)%10007;    
        printf("%d\n",sum2); 
    }
    return 0;
}
