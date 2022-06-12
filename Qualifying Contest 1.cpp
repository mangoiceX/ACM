#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int maxn = 2e5 + 100;

struct node{
    string name;
    int score;
    node(string _name, int _score){
        name = _name;
        score = _score;
    }
};
 
vector<node>no[maxn];
 
bool cmp(node a, node b){
    return a.score > b.score;
}
 
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
        for(int i=1; i<=m; i++){
        	no[i].clear();
		}   
        int num,score;
        string name;
        for(int i=0; i<n; i++){
            cin>>name>>num>>score;
            no[num].push_back(node(name, score));
        }
        for(int i=1; i<=m; i++){
            sort(no[i].begin(), no[i].end(), cmp);
            int len = no[i].size();
            if(len>2 && no[i][1].score==no[i][2].score)
                puts("?");
            else
                cout<<no[i][0].name<<" "<<no[i][1].name<<endl;
        }
    }
    return 0;
}

