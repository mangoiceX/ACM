#include <iostream>  
#include <queue>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <cstdio>  
using namespace std;  
  
int n;  
double map[202][202];  
  
struct point  
{  
    int x,y;  
}po[202];  
  
  
int work()  
{  
   for(int k=1;k<=n;k++)  
   for(int i=1;i<=n;i++)  
   for(int j=1;j<=n;j++)  
   {  
       if(i!=j&&i!=k&&j!=k&&max(map[i][k],map[j][k])<map[i][j])map[i][j]=max(map[i][k],map[j][k]);  
   }  
  
  
  
}  
  
  
int main()  
{   int t=0;  
  
    while(cin>>n)  
    {  if(n==0)break;  
        t++;  
         memset(po,0,sizeof(po));  
     for(int i=1;i<=n;i++)  
     {int xx,yy;  
         cin>>xx>>yy;  
  
         po[i].x=xx;po[i].y=yy;  
  
     }  
  
      memset(map,0x7f,sizeof(map));  
     for(int i=1;i<=n;i++)  
     {  
         for(int j=1;j<=n;j++)  
         {  
             map[i][j]=map[j][i]=sqrt((po[i].x-po[j].x)*(po[i].x-po[j].x)+(po[i].y-po[j].y)*(po[i].y-po[j].y));  
         }  
     }  
  
  
  
  
  
     work();  
     cout<<"Scenario #"<<t<<endl;  
  
     printf("Frog Distance = %.3f\n\n",map[1][2]);  
  
  
    }  
  
    return 0;  
}  
