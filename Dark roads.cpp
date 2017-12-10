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
vector<pii>vec[N];
bool vis[N];
ll mst(ll start)
{
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(mp(0,start));
    ll cost=0;
    while(!pq.empty())
    {
        ll val=pq.top().ff;
        ll node=pq.top().ss;
        pq.pop();
        if(vis[node]==true)
            continue;
        cost+=val;
        vis[node]=true;
        fr(i,0,vec[node].size())
        {
            if(vis[vec[node][i].ss]==false)
                pq.push(vec[node][i]);
        }
    }
    //cout<<cost<<"\n";
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(true)
    {
        ll n,m,x,y,z,ans=0;
        cin>>m>>n;
        if(n==0 && m==0)
            break;
        else
        {
            fr(i,0,n)
            {
                cin>>x>>y>>z;
                ans+=z;
                vec[x].pb(mp(z,y));
                vec[y].pb(mp(z,x));
            }
            memset(vis,false,sizeof(vis));
            ans-=mst(0);
            cout<<ans<<"\n";
        }
        fr(i,0,N)
            vec[i].clear();
    }
    return 0;
}
