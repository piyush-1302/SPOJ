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
#define ll int
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
vector<pii>vec[N];
bool vis[N];
ll prim(ll a)
{
    priority_queue<pii, vector<pii>, greater<pii> >q;
    //vis[a]=true;
    q.push(pii(0,a));
    ll cost=0;
    while(!q.empty())
    {
        ll val=q.top().ff;
        ll num=q.top().ss;
        q.pop();
        if(vis[num]==true)
            continue;
        cost+=val;
        vis[num]=true;
        fr(i,0,vec[num].size())
        {
            if(vis[vec[num][i].ss]==false)
                q.push(vec[num][i]);
        }
    }
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,m,x,y,w,i,ans;
    cin>>n>>m;
    fr(i,0,m)
    {
        cin>>x>>y>>w;
        vec[x].pb(pii(w,y));
        vec[y].pb(pii(w,x));
    }
    memset(vis,false,sizeof vis);
    ans=prim(1);
    cout<<ans<<"\n";
    return 0;
}
