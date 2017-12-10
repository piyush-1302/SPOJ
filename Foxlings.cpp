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
const int N=100007;
map<ll,ll>mymap;
ll root(ll x)
{
    while(x!=mymap[x])
    {
        mymap[x]=mymap[mymap[x]];
        x=mymap[x];
    }
    return x;
}
void uni(ll a, ll b)
{
    mymap[b]=a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,x,y,m;
    cin>>n>>m;
    ll cnt=n;
    while(m--)
    {
        cin>>x>>y;
        if(!mymap[x])
            mymap[x]=x;
        if(!mymap[y])
            mymap[y]=y;
        ll a=root(x);
        ll b=root(y);
        if(a!=b)
        {
            cnt--;
            uni(a,b);
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
