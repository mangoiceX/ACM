#include <iostream>
#include <cstdio>

using namespace std;
 
const int N = 1000000;
 
struct Elem
{
	int height;
	int count;
};
const int maxn=1000 + 10;
char mp[maxn][maxn];
int height[maxn][maxn];
Elem stack[N];
int top;
int n,m;
int main()
{
	long long ans1=0,ans2=0, tot, tmp;
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=m;i++)
			height[0][i]=0;
		// getchar();
		for(int i=1;i<=n;i++){
			// for(int j=1;j<=m;j++){
			// 	scanf("%c",&mp[i][j]);
			// }
			// getchar();
			scanf("%s",mp[i]+1);
		}
		for(int i=1;i<=n;i++)
		{
			top = 0;
			for (int j=1;j<=m;++j)
			{
				if(mp[i][j]=='1')
					height[i][j]=height[i-1][j]+1;
				else height[i][j]=0;
				//cout<<height[i][j]<<" ";
				tmp = 0;
				while (top > 0 && stack[top - 1].height > height[i][j])
				{
					tot = stack[top - 1].height * (stack[top - 1].count + tmp);
					if (tot >= ans1) {
						ans2 = ans1;
						ans1 = tot;
					}
					else if(tot>=ans2){
						ans2=tot;
					}
					tmp += stack[top - 1].count;
					--top;
				}
				stack[top].height = height[i][j];
				stack[top].count = 1 + tmp;
				++top;
			}
			//cout<<endl;
			tmp = 0;
			while (top > 0)
			{
				tot = stack[top - 1].height * (stack[top - 1].count + tmp);
				if (tot >= ans1) {
					ans2 = ans1;
					ans1 = tot;
				}
				else if(tot>=ans2){
					ans2=tot;
				}
				tmp += stack[top - 1].count;
				--top;
			}
		}
		printf("%lld\n", ans2);
	}
	return 0;
}
