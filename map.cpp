
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#define MAXN 10010
#define RST(N)memset(N, 0, sizeof(N))
using namespace std;
 
struct Node
{
    string name;
    float score;
    bool operator < (const Node &a) const
    {
        return a.score < score ;
    }
};
 
map <Node, int> mp;
map <Node, int> :: iterator _it;
map <Node, int> :: reverse_iterator _rit;
 
int main()
{
    int n;
    Node N;
    while(cin >> n) {
	mp.clear();
        for(int i=0; i<n; i++) {
            cin >> N.name >> N.score;
            mp[N]++;
        }
        for(_it=mp.begin(); _it!=mp.end(); _it++) {
            cout << (_it->first).name << " : " << (_it->first).score << endl;
        }
    }
    return 0;
}

