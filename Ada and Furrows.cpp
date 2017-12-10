#include<bits/stdc++.h>
/*#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<math>
#include<set>
#include<iterator>
#include<tuple>*/
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
#define mod 1000000007
#define pii pair<ll,ll>
const int N=20007;
int main()
{
    ios_base::sync_with_stdio(false);
    ll q,x,y;
    bitset<N>ans[N];
    cin>>q;
    char c;
    while(q--)
    {
        cin>>c>>x>>y;
        if (c=='+')
            ans[x][y]=1;
        else if(c=='-')
            ans[x][y]=0;
        else if(c=='v')
            cout<<(ll)((ans[x] | ans[y]).count());
        else if(c=='^')
            cout<<(ll)((ans[x] & ans[y]).count());
        else if(c=='!')
            cout<<(ll)((ans[x] | ans[y]).count())-(ll)((ans[x] & ans[y]).count());
        else
            cout<<(ll)((ans[x] ^ (ans[x] & ans[y])).count());
        cout<<"\n";
    }
    return 0;
}
