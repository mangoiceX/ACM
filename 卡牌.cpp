
#include <cstdio>
#include <cstring>
 int main()
 {
    int m, n, i, j, tmp, count=0,d[10];
    int large_cards=0, ans=0;
    bool cards[1050];
     while(scanf("%d %d", &m, &n)&&m&&n)
	 {
        memset(cards, false, sizeof(cards));
        for(i=0; i<n; i++)
		{
           scanf("%d", &j);            
		    cards[j] = true;
        }
        int large_cards=0,ans=0,end = 0;;
		for(i = m*n; i>0; i--)
		{
             if(!cards[i]) 
			 	large_cards++;
             else
			 {
			 	end++;
                 if(large_cards == 0) ans++;
                 else large_cards--;
             }
             if(end == n)
             	break;
         }
         d[count]=ans;
         count++;
     }
     for(i=0;i<count;i++) 
    	printf("Case %d: %d\n", i+1,d[i]);
     return 0;
}
 
