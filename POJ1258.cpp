/*Answer:  POJ1258*/
#include<stdio.h>  
#include<iostream>  
#include<algorithm>  
#include<math.h>  
#include<cctype>
#include<cstring>
#define INF 999999  
#define M 105  
using namespace std;  
  
int map[M][M],dis[M];     
int vis[M];  
  
int main ()  
{  
    int n;  
    int i,j;  
    int temp,sum ;  
    while(cin>>n)  
    {  
        memset(map,0,sizeof(map));  
        memset(vis,0,sizeof(vis));  
          
        for(i=1;i<=n;i++)  
            for(j=1;j<=n;j++)  
                cin>>map[i][j];  
          
            for(i=1;i<=n;i++)  
                dis[i]=map[1][i];  
              
            vis[1]=1;  
            sum=0;  
  
            for(i=1;i<n;i++)  
            {   
                int min=INF;  
                for(j=1;j<=n;j++)  
                {  
                    if(!vis[j] && dis[j]<min)  
                    {  
                        min=dis[j];  
                        temp=j;   
                    }  
                }  
                sum+=min;  
                vis[temp]=1;  
                  
                for(j=1;j<=n;j++)  
                {  
                    if(!vis[j] && dis[j]>map[temp][j])  
                        dis[j]=map[temp][j];  
                }  
            }  
            cout<<sum<<endl;  
    }  
    return 0;  
}  

