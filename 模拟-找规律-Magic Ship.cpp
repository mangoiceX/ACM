#include<bits/stdc++.h>
#define per(i,a,b) for(int i = (a);i <= (b);++i)
#define INF 0x3f3f3f
typedef long long LL;
using namespace std; 
const int maxn = 1e5;
int s0 = 0,e0 = 0,s1 = 0,e1 = 0;
char str[maxn+10];
int n = 0;
bool dic[5];//l,r,u,d
char ss[5] = {'0','L','R','U','D'};
void solve(){		
	map<char,int> mp,mp2;
	mp['L'] = 1,mp['R'] = 2,mp['U'] = 3,mp['D'] = 4;
	

	int x = 0,y = 0;
	int minv = min(abs(s1 - s0),abs(e0 - e1));	
	int maxv = max(abs(s1 - s0),abs(e0 - e1));
	memset(dic,false,sizeof(dic));
		
	per(i,0,n-1){
		++mp2[str[i]];
	}
	int ans = 0;
	if(s0 == s1 || e0 == e1){
		if(s0 == s1){
			if(e0 < e1){
				if(mp2['U'] == 0){
					printf("-1\n");
					return ;	
				}else{
					int tmp = maxv - 2*mp2['U'];
					if(tmp > 0){
						ans += (((maxv+1)/2) / mp2['U'] ) * n;
					}else{
						tmp = (maxv + 1) / 2;
					}
					int cnt = 0;
					per(i,0,n-1){
						if(cnt >= tmp){
							break;
						}
						if(str[i] == 'U'){
							++cnt;
						}
						++ans;
					}
				}
			}
			if(e0 > e1){
				if(mp2['D'] == 0){
					printf("-1\n");
					return ;	
				}else{
					int tmp = maxv - 2*mp2['D'];
					if(tmp > 0){
						ans += (((maxv+1)/2) / mp2['D'] ) * n;
					}else{
						tmp = (maxv + 1) / 2;
					}
					//ans += (((maxv+1)/2) / mp2['D']) * n;
					//cout << "haha " << ans  << " " <<maxv << " " << mp2['D']<< endl;
					//int tmp = min(maxv - 2*mp2['D'],0);
					int cnt = 0;
					per(i,0,n-1){
						if(cnt >= tmp){
							break;
						}
						if(str[i] == 'D'){
							++cnt;
						}
						++ans;
					}
				}
			}
		}else{
			if(s0 < s1 ){
				if(mp2['R'] == 0){
					printf("-1\n");
					return ;	
				}else{
					//ans += (((maxv+1)/2)/ mp2['R']) * n;
					//int tmp = min(maxv - 2*mp2['R'],0);
					int tmp = maxv - 2*mp2['R'];
					if(tmp > 0){
						ans += (((maxv+1)/2) / mp2['R'] ) * n;
					}else{
						tmp = (maxv + 1) / 2;
					}
					int cnt = 0;
					per(i,0,n-1){
						if(cnt >= tmp){
							break;
						}
						if(str[i] == 'R'){
							++cnt;
						}
						++ans;
					}
					
				}
			}
			if(s0 > s1 ){
				if(mp2['L'] == 0){
					printf("-1\n");
					return ;	
				}else{
					int tmp = maxv - 2*mp2['L'];
					if(tmp > 0){
						ans += (((maxv+1)/2) / mp2['L'] ) * n;
					}else{
						tmp = (maxv + 1) / 2;
					}
					//ans += (((maxv+1)/2) / mp2['L']) * n;
					//int tmp = min(maxv - 2*mp2['L'],0);
					int cnt = 0;
					per(i,0,n-1){
						if(cnt >= tmp){
							break;
						}
						if(str[i] == 'L'){
							++cnt;
						}
						++ans;
					}
				}	
				
			}
		}
		printf("%d\n",ans);
		return ;
	}
	
	if(s0 < s1 && e0 < e1){
		x = s1 - minv,y = e1 - minv;
		dic[2] = dic[3] = true;
		//dic[2] = (s0 == s1 ? false : true);
	//dic[3] = (e0 == e1 ? false : true);
	}else if(s0 > s1 && e0 > e1){
		x = s1 + minv,y = e1 + minv;
		dic[1] = dic[4] = true;
	}else if(s0 > s1 && e0 < e1){
		x = s1 + minv,y = e1 - minv;
		dic[1] = dic[3] = true;
		//dic[1] = (s0 == s1 ? false : true);
		//dic[3] = (e0 == e1 ? false :true);
	}else if(s0 < s1 && e0 > e1){
		x = s1 - minv,y = e1 + minv;
		dic[2] = dic[4] = true;
	}
	char right[2];
	int si = 0;
	per(i,1,4){
		if(dic[i]){
			right[si++] = ss[i];
		}
	}
	//printf("%c %c\n",right[0],right[1]);
	if((mp2[right[0]] == 0 && mp2[right[1]] == 0) ){
		printf("-1\n");
		return ;
	}
	
	ans = 0;
	
	int t1 = (abs(x - s0) + 1) / 2 ,t2 = (abs(y - e0) + 1) / 2;
	int id = (t1 > 0 ? 0 : 1),res = max(t1,t2);
	
	int tmp = t1 - mp2['L'];
	if(tmp > 0){
		ans += (res / mp2[right[id]]) * n;
	}else{
		tmp = t1 - mp2['L'];
	}
	//ans += (res / mp2[right[id]]) * n;
	//int tmp = res % mp2[right[id]];
	int loc = -1;
	if(tmp != 0){
		int cnt = 0;
		per(i,0,n-1){
			if(cnt >= tmp){
				loc = i;
				break;
			}
			if(str[i] == right[id]){
				++cnt;
			}
			++ans;
		}
	}
	
	per(i,loc,n-1){
		if(minv == 0){
			break;
		}
		if(str[i] == right[0] || str[i] == right[1]){
			--minv;
		}
		++ans;
	}
	
	ans += (minv / (mp2[right[0]] + mp2[right[1]])) * n;
	tmp = minv % (mp2[right[0]] + mp2[right[1]]);
	
	per(i,0,n-1){
		if(tmp == 0){
			break;
		}
		if(str[i] == right[0] || str[i] == right[1]){
			--tmp;
		}
		++ans;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d %d",&s0,&e0);
	scanf("%d %d",&s1,&e1);
	scanf("%d",&n);
	scanf("%s",str);
	//cout << "nia " << s0 <<" " << s1 << endl; 
	solve();
	return 0;
}

