#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll re(ll x){
    x++;
    while(x%10==0)
        x/=10;
    return x;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    set<int> se;
    ll n;
    cin>>n;
    se.insert(n);
    ll tmp=n;
    while(tmp%10==0)
        tmp/=10;
    se.insert(tmp);
    se.insert(re(n));
    int last=0;
    n=re(n);
    while(se.size()!=last){
        last=se.size();
        se.insert(re(n));
        n=re(n);
        se.insert(n);
    }
    cout<<se.size();
    return 0;
}
