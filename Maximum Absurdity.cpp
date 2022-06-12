#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 2e6 + 100;
typedef unsigned long long LL; 
LL data[maxn];
LL tree[maxn];
int n = 0,k = 0;
struct Node{
	LL sum = 0;
	int is1,is2;
	int is;
};

Node node[maxn],ans[maxn];
bool cmp(Node a,Node b){
	if(a.sum != b.sum){
		return a.sum > b.sum;
	}else{
		return a.is < b.is;	
	}
	
}

bool cmp1(Node a,Node b){
	if(a.sum != b.sum){
		return a.sum > b.sum;
	}else if(a.is1 != b.is1){
		return a.is1 < b.is1;	
	}else{
		return a.is2 < b.is2;
	}
	
}

int lowbit(int x){
	return x & (-x);
}

void update(int loc,int val){
	while(loc <= n){
		tree[loc] += val;
		loc += lowbit(loc);
	}
}

int getsum(int loc){
	int sum = 0;
	while(loc > 0){
		sum += tree[loc];
		loc -= lowbit(loc);
	}
	return sum;
}

int main(){
	
	cin >> n >> k;
	memset(tree,0,sizeof(tree));
	for(int i = 1;i <= n;++i ){
		cin >> data[i];
		update(i,data[i]);
	}
//	for(int i = 1;i <= n;++i){
	//	cout << tree[i] << " ";
//	}
//	cout << endl;
	for(int i = k;i <= n;++i){
		node[i-k+1].is = i-k+1;
		node[i-k+1].sum = getsum(i) - getsum(i-k);
	}
	//for(int i = 1;i <= n;++i){
//		cout << node[i].sum << " ";
//	}
//	cout << endl;
	sort(node+1,node+n-k+1+1,cmp);
///	for(int i = 1;i <= n;++i){
//		cout << node[i].sum << " ";
	//}
//	cout << endl;
	int cnt = 0;
	for(int i = 1;i <= n - k +1;++i){
		for(int j = i + 1;j <= n - k +1;++j){
			if(abs(node[i].is - node[j].is )>= k){
				ans[cnt].sum = node[i].sum + node[j].sum;
				ans[cnt].is1 = min(node[i].is ,node[j].is);
				ans[cnt].is2 = max(node[i].is ,node[j].is);
				++cnt;
				break;
			}
		}
	}
	sort(ans,ans + cnt,cmp1);
	//for(int i = 0;i < cnt;++i){
	//	cout << ans[i].sum << " ";
//	}
//	cout << endl;
	cout << ans[0].is1 << " " << ans[0].is2 << endl;
	
	/*
	for(int i = 1;i <= n - k + 1;++i){
		tree[i] = 0;
		update(i,node[i].sum); 
	}
	for(int i = 1;i <= n - k+1;++i){
			
	}
	*/
//	for(int i = 1;i <= n;++i){
	//	cout << node[i].sum << " ";
//	}
//	cout << endl;
/*
	int flag = 0;
	
	for(int i = 1;i <= n-k+1;++i){
		for(int j = i + 1;j <= n-k+1;++j){
			if(abs(node[i].is - node[j].is )>= k){
				int ma = max(node[i].is ,node[j].is);
				int mi = min(node[i].is ,node[j].is);
				cout << mi << " " << ma << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			break;
		}	
	}
*/
	return 0;
}
