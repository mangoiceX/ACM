#include<stdio.h>  
#include<string.h>  
#define INF 0x7ffffff  
#define Max 2510  
int map[Max][Max];  
int n,m,ts,te,t;  
//int ev[Max*2],last[Max*2],nbs[Max];  
void dijkstra(int x)  
{  
    int dis[Max],vis[Max],i,j,minn,flag;  
    memset(dis,0,sizeof(dis));  
    memset(vis,0,sizeof(vis));  
    for(i=1;i<=n;i++)  
        dis[i]=map[x][i];  
    dis[x]=0,vis[x]=1;  
    for(i=1;i<n;i++)  
    {  
        minn=INF;  
        for(j=1;j<=n;j++)  
            if(!vis[j]&&dis[j]<minn) //找到联通的点最小的边 
            {  
                flag=j;  
                minn=dis[j];  
            }  
            vis[flag]=1;  //标记 
            /*for(j=nbs[flag];j;j=last[j]) 
                if(vis[ev[j]]==0&&map[flag][ev[j]]<INF&&dis[flag]+map[flag][ev[j]]<dis[ev[j]]) 
                    dis[ev[j]]=dis[flag]+map[flag][ev[j]];*/  
            for(j=1;j<=n;j++)  
                if(!vis[j]&& map[flag][j] > 0)
					if(dis[flag]+map[flag][j]<dis[j])  
                    dis[j]=map[flag][j]+dis[flag];  
    }  
    printf("%d\n",dis[te]);  
}  
int main()  
{  
    //freopen("b.txt","r",stdin);  
    int i,j,a,b,c;  
    while(scanf("%d %d %d %d",&n,&m,&ts,&te)==4)  
    {  
        //memset(nbs,0,sizeof(nbs));  
        //memset(ev,0,sizeof(ev));  
    //  memset(last,0,sizeof(last));  
        for(i=1;i<=n;i++)  
            for(j=1;j<=n;j++)  
                map[i][j]=INF;  
            t=0;  
        for(i=1;i<=m;i++)  
        {  
            scanf("%d %d %d",&a,&b,&c);  
            map[b][a]=map[a][b]=c;  
         //last[++t]=nbs[a]; nbs[a]=t; ev[t]=b;   
            //last[++t]=nbs[b]; nbs[b]=t; ev[t]=a;  
        }  
            dijkstra(ts);  
    }  
    return 0;  
}  
