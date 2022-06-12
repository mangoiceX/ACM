#include<bits/stdc++.h> 
using namespace std;
const int maxn = 500 + 10;
int n = 0,m = 0;
int r1 = 0,c1 = 0,r2 = 0,c2 = 0;
char mp[maxn][maxn];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct node{
	int r,c;
	node(int rr = 0,int cc = 0):r(rr),c(cc){//���캯�� 
		
	}
};
bool bfs(){
	queue<node> que;
	que.push(node(r1,c1));
	while(!que.empty()){
		node u = que.front();
		que.pop();
		for(int i = 0;i < 4;++i){
			int x = u.r + dx[i],y = u.c + dy[i];
			if(x < 0 || x >= n || y < 0 || y >= m){
				continue;
			}
			if(mp[x][y] == 'X' && (x == r2 && y == c2)){
				return true;
			}
			if(mp[x][y] == '.'){
				mp[x][y] = 'X';
				que.push(node(x,y));
			}
		}
	}
	return false;
}

int main(){
	while(cin >> n >> m){
		for(int i = 0;i < n;++i){//�ַ��������ʱ���Ǵ�1��ʼ�ģ�����ȫ��ͳһ��0��ʼ�� 
			cin >> mp[i];
		}	
		cin >> r1 >> c1;
		cin >> r2 >> c2;
		--r1,--c1,--r2,--c2; //ע��Ҫ��1 
		if(bfs()){
			cout << "YES\n";
		}else{
			cout <<  "NO\n";
		}
		//cout << (bfs() == true )? "YES\n" : "NO\n"; //����д���Ǵ���� 
	}
	
	return 0;
}
