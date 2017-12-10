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
const int N=200007;
vector<pair<ll,pair<ll,ll> > >vec;
ll parent[N],sz[N];
void init()
{
    fr(i,0,N)
    {
        parent[i]=i;
        sz[i]=1;
    }
}
ll root(ll x)
{
    while(x!=parent[x])
    {
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}
void uni(ll x, ll y)
{
    if(sz[x]>sz[y])
    {
        sz[x]+=sz[y];
        parent[y]=parent[x];
    }
    else
    {
        sz[y]+=sz[x];
        parent[x]=parent[y];
    }
}
ll kruskal()
{
    ll x,y,cost=0,node1,node2,cst;
    fr(i,0,vec.size())
    {
        cst=vec[i].ff;
        node1=vec[i].ss.ff;
        node2=vec[i].ss.ss;
        ll r1,r2;
        r1=root(node1);
        r2=root(node2);
        if(r1!=r2)
        {
            cost+=cst;
            uni(r1,r2);
        }
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,ar[N],x,y,z,flag=1;
        cin>>n>>m;
        fr(i,1,n+1)
        {
            cin>>ar[i];
            if(ar[i]==1)
                vec.pb(mp(0,mp(n+1,i)));
        }
        if(vec.size()==0)
            flag=0;
        //else
        {
            fr(i,0,m)
            {
                cin>>x>>y>>z;
                vec.pb(mp(z,mp(x,y)));
            }
            sort(vec.begin(),vec.end());
            init();
            ll ans=kruskal();
            fr(i,1,n+1)
            {
                //cout<<root(i)<<"   ";
                if(root(i)!=root(n+1))
                {
                    flag=0;
                    break;
                }
            }
            if(!flag)
                cout<<"impossible\n";
            else
                cout<<ans<<"\n";
        }
        vec.clear();
    }
    return 0;
}

