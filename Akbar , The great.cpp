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
const int N=1000007;
vector<ll>adj[N];
ll dis[N],soldier[N];
int bfs(ll source, ll d, ll cnt)
{
    queue<pair<ll,pii> >q;
    q.push(mp(-1,mp(source,d)));
    ll parent,node,di;
    while(!q.empty())
    {
        parent=q.front().ff;
        node=q.front().ss.ff;
        di=q.front().ss.ss;
        q.pop();
        if(di>0)
        {
            fr(i,0,adj[node].size())
            {
                if(adj[node][i]!=parent && dis[adj[node][i]]==-1)
                {
                    dis[adj[node][i]]=di-1;
                    soldier[adj[node][i]]=cnt;
                    q.push(mp(node,mp(adj[node][i],di-1)));
                }
                else if(adj[node][i]!=parent && dis[adj[node][i]]>-1 && soldier[adj[node][i]]!=cnt)
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll t,j,r,i;
    cin>>t;
    while(t--)
    {
        ll n,m,x,y,ans;
        cin>>n>>r>>m;
        fr(i,0,r)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        memset(dis,-1,sizeof(dis));
        memset(soldier,0,sizeof(soldier));
        ll a,index;
        ans=1;
        fr(i,0,m)
        {
            cin>>x>>y;
            if(dis[x]!=-1)
                ans=0;
            dis[x]=y;
            soldier[x]=i+1;
            if(ans)
                ans=bfs(x,y,i+1);
        }
        //cout<<ans<<"\n";
        if(!ans)
            cout<<"No\n";
        else
        {
            fr(i,1,n+1)
            {
               // cout<<dis[i]<<"  ";
                if(dis[i]==-1)
                {
                    cout<<"No\n";
                    ans=0;
                    break;
                }
            }
            if(ans)
                cout<<"Yes\n";
        }
        for(j=0;j<=n;j++)
            adj[j].clear();
    }
    return 0;
}
