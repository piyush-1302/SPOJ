#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frn(i,a,b) for(ll i=a;i<=b;i++)
#define frb(i,a,b) for(ll i=a;i>=b;i--)
#define ssi(a) scanf("%lld",&a)
#define si(a) scanf("%d",&a)
const int N=507;
#define pr pair<ll,ll>
vector<pr>adj[N];
ll dis[N];
struct comp
{
    int operator() (const pair<int,int>&p1,const pair<int,int>&p2)
    {
        return p1.second<p2.second;
    }
}p;
void dij(ll u, ll v)
{
    priority_queue<pr,vector<pr>,comp> q;
    dis[u]=0;
    q.push(pr(u,dis[u]));
    while(!q.empty())
    {
        ll a1=q.top().ff;
        ll num1,num2;
        q.pop();
        fr(i,0,adj[a1].size())
        {
            num1=adj[a1][i].ff;
            num2=adj[a1][i].ss;
            if(dis[num1]>dis[a1]+num2)
            {
                dis[num1]=dis[a1]+num2;
                q.push(pr(num1,dis[num1]));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll n,q,u,v,x,y,w,i;
    cin>>n;
    fr(i,0,n)
    {
        cin>>x>>y>>w;
        adj[x].pb(pr(y,w));
        adj[y].pb(pr(x,w));
    }
    cin>>u;
    cin>>q;
    while(q--)
    {
        cin>>v;
        memset(dis,1000007,sizeof dis);
        dij(u,v);
        if(dis[v]>=1000007)
            cout<<"NO PATH\n";
        else
            cout<<dis[v]<<"\n";
    }
    return 0;
}
